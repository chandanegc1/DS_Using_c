var fs = require('fs');
var argv = process.argv.slice(2);
var child_process = require('child_process');
var testfile;

function printUsage() {
    var usage = [
        'Usage :',
        'node runTestForC.js test_file.c dependency_file.c -w==> runs all tests',
        'node runTestForC.js test_file.c dependency_file.c -w -list ==> lists all tests',
        'node runTestForC.js test_file.c dependency_file.c -w -stop ==> stops on first failure',
        'node runTestForC.js test_file.c dependency_file.c -w -only namePart ==> runs all tests that match the namePart',
        '-w is optional to avoid compiler warning'
    ];
    console.log(usage.join('\t\n'));
}


function isOption (arg){return (arg[0] =='-'&&arg.length>2);};
function isGccCommand (arg){return (arg[0] =='-'&&arg.length==2);};

function isFile(argv){
    return argv.join(' ').match(/\b\w+\.\w+/g);
};

function readFile(fileName) {
    try {
        return fs.readFileSync('./' + fileName, 'utf-8');
    } catch (e) {
        console.log(e.message);
    }
};

function extractTests(fileContent) {
    var tests = fileContent.match(/(\btest_\w+)/g);
    if(tests == null) return [];
    return tests.map(function(test) {
        return test + "\(\);";
    });
};

function printFormattedErr(stderr,err) {
   process.stdout.write(stderr);
   err&&console.log(err);
}

function printResult(test, allTests, summary,dependency,stop) {
    return function(err, stdout, stderr) {
        printTestName(test);
        if (stdout) console.log(stdout);
        if (err || stderr) summary.failed++,printFormattedErr(stderr,err);
        else summary.passed++
        console.log('--------------');
        runAllTests(allTests, summary,dependency,stop);
    }
}

function createFile(test) {
    var sample = ["#include <stdio.h>",
        "#include \"" + testfile + "\"",
        "int main(void) {"
    ];
    return sample.join('\n') + test + 'return 0;}';
}

function printTestName(test) {
    console.log('===>', test.substr(0, test.length - 3));
}

function listTestNames(tests) {
    console.log("loading tests from " + testfile + "\n--------------");
    tests.forEach(printTestName);
}

function printTestCounts(summary) {
    console.log('Passed/Total :\t', (summary.passed) + '/' + (summary.passed+summary.failed));
    if(fs.existsSync('all_test_c_'))
      child_process.execSync('rm all_test_c_  test_runner_file_.c');
};

function runAllTests(tests, summary,dependency,stop) {

    if ((tests.length==0)||(stop&&summary.failed)) {
        printTestCounts(summary);
        return;
    }
    var test = tests.shift();
    var mainFile = createFile(test,testfile);
    fs.writeFileSync('test_runner_file_.c', mainFile);
    var command = 'gcc -o all_test_c_ test_runner_file_.c ';
    if(dependency) command += dependency;
    try{
        child_process.execSync(command);
        child_process.exec('./all_test_c_', printResult(test, tests, summary,dependency,stop));
    }catch(e){ console.log(e.message)};
    
};

function matchedTest(option){
    return function(test){
        return test.match(option);
    };
};

function optionManager(tests,option,dependency){
    var summary = {failed: 0,passed:0 };
    if(option == '-list')
        listTestNames(tests);
    if(option == '-help')
        printUsage();
    if(option == '-stop'){
        runAllTests(tests,summary,dependency,true);
    };
    if(option.length>1&&option[0]=='-only'){
        tests = tests.filter(matchedTest(option[1]));
        runAllTests(tests,summary,dependency);
    }
}


function main() {
    var files = isFile(argv)||[];
    var gccCommand = argv.filter(isGccCommand).join('');
    var gccCommandIndex = argv.indexOf(gccCommand)>=0?1:0;
    var lastFileIndex = argv.indexOf(files[files.length-1]);
    var option  = argv.slice(lastFileIndex+gccCommandIndex+1);
    testfile = files[0];
    var dependency = files.slice(1).join(' ') +' '+gccCommand;
    if (testfile) {
        var fileContent = readFile(testfile);
        var tests = extractTests(fileContent);
        var summary = {failed: 0,passed:0 };
        if (option.length>0)
            optionManager(tests,option,dependency);
        else{
            console.log("loading tests from " + testfile + "\n--------------");
            runAllTests(tests, summary,dependency);
        };
    } else
        printUsage();
};
main();