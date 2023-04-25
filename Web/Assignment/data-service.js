var fs=require('node:fs/promises');
var stud=require('./data/students.json');
var prog=require('./data/programs.json');

var students=[];
var intstudents=[];
var programs=[];
var stud;
var prog;

fs.readFile('./data/students.json','utf8',(err,data)=>{
if(err) throw err;
stud = JSON.parse(data);
});
fs.readFile('./data/programs.json','utf8',(err,data)=>{
    if(err) throw err;
    prog = JSON.parse(data);
    });
    
module.exports.initialize=function()
{
    
    return new Promise( (resolve, reject) => {
        students = stud.slice();
        programs=prog.slice();
    
    if(students.length==0||programs.length==0)
    {
        reject("unable to read file");return;
    }
    resolve();
    
});
}
module.exports.getAllStudents = function(){
    return new Promise((resolve,reject)=>{
        if (students.length == 0) {
            reject("query returned 0 results"); return;
        }

        resolve(students);
    })
}

module.exports.getInternationalStudents = function(){ // user element position in the array to mimic id
    return new Promise((resolve,reject)=>{
        intstudents = students.filter(student=>student.isInternationalStudent===true);
        resolve(intstudents);
        if(intstudents.length==0)
        {
            reject("no results returned"); return;
        }
    })
}
    module.exports.getPrograms = function(){
        return new Promise((resolve,reject)=>{
            if (programs.length == 0) {
                reject("no results returned"); return;
            }
    
            resolve(programs);
        })
    }
    function maxStudent()
    {
        var st = json.parse(stud);
        var max;
        for(var i = 0;i<st.length;i++)
        {
            if(parseInt(students[i].studentID)>parseInt(stud[i+1].studentID))
            {
                max = parseInt(stud[i].studentID);
            }
            else
            {
                max = parseInt(stud[i+1].studentID);
            }
        }
        return max;
    }
    module.exports.addStudent = function(studentData){
        if(!studentData.isInternationalStudent==undefined){
            studentData.isInternationalStudent = false;
        } else{
            studentData.isInternationalStudent = true;
        }   
         
        studentData.studentID = students.length + 1;
        students.push(studentData);
        return new Promise((resolve, reject) => {
            resolve(students);
            if(students.length == 0){
                reject("Nothing found");
            }        
        });
    };
    module.exports.getStudentsByStatus = function(status){
        return new Promise((resolve, reject) => {
            let filteredStudents = students.filter(students => students.status == status);
            resolve(filteredStudents);
            if(filteredStudents.length == 0){
                reject("no results returned");
            }        
        });
    }
    module.exports.getStudentsByProgramCode = function(programCode){
        return new Promise((resolve, reject) => {
            let filteredStudents = students.filter(students => students.programCode == programCode);
            resolve(filteredStudents);
            if(filteredStudents.length == 0){
                reject("no results returned");
            }        
        });
    }
    module.exports.getStudentsByExpectedCredential = function(credential){
        return new Promise((resolve, reject) => {
            let filteredStudents = students.filter(students => students.expectedCredential == credential);
            resolve(filteredStudents);
            if(filteredStudents.length == 0){
                reject("no results returned");
            }        
        });
    }
    module.exports.getStudentById = function(sid){
        return new Promise((resolve, reject) => {
            let filteredStudents = students.filter(students => students.studentID == sid);
            resolve(filteredStudents);
            if(filteredStudents.length == 0){
                reject("no results returned");
            }        
        });
    }
    



