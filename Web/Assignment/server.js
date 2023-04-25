/*********************************************************************************
*  WEB322 – Assignment 03
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  No part *  of this assignment has been copied manually or electronically from any other source 
*  (including 3rd party web sites) or distributed to other students.
*
*  Name: Datmehar Singh,  Student ID: 108011214, Date: 14-10-2022
*
*  Online (Cyclic) Link: https://frantic-newt-school-uniform.cyclic.app/
*
********************************************************************************/ 

const path = require('path');
var data = require('./data-service');
const multer = require("multer");
var fs=require('fs');
var express = require("express");
var bodyParser = require("body-parser");
//const { rmSync } = require('fs');
var app = express();
var HTTP_PORT = process.env.PORT || 8080;

// call this function after the http server starts listening for requests
function onHttpStart() {
  console.log("Express http server listening on: " + HTTP_PORT);
}
app.use(express.static(path.join(__dirname, 'public')));

// setup a 'route' to listen on the default url path (http://localhost)
app.get("/", function(req,res){
    res.sendFile(path.join(__dirname,"/views/home.html"));
});
app.get("/home", function(req,res){
  res.sendFile(path.join(__dirname,"/views/home.html"));
});
// setup another route to listen on /about
app.get("/about", function(req,res){
  res.sendFile(path.join(__dirname,"/views/about.html"));
});

app.get("/students/add", function(req,res){
  res.sendFile(path.join(__dirname, "/views/addStudent.html"));
})


app.get("/students", (req,res) => {
  data.getAllStudents().then((data)=>{
      res.json(data); 
  }).catch((err)=>{
      res.send(err);
  });
});

app.get("/intlstudents", (req,res) => {
  data.getInternationalStudents().then((data)=>{
      res.json(data); 
  }).catch((err)=>{
      res.send(err);
  });
});

app.get("/programs", (req,res) => {
  data.getPrograms().then((data)=>{
      res.json(data); 
  }).catch((err)=>{
      res.send(err);
  });
});

app.get("/images/add", function (req, res) {
  res.sendFile(path.join(__dirname, "/views/addImage.html"));
});


const storage = multer.diskStorage({
  destination: "./public/images/uploaded",
  filename:  function (req, file, cb) {
    cb(null, Date.now() + path.extname(file.originalname));
  }

});

const upload = multer({storage:storage});

app.post("/images/add", upload.single("imageFile"), (req, res) => {
  res.redirect("/images");
}); 

app.get("/images", (req, res) => {
  fs.readdir("./public/images/uploaded", function(err, imageFile){
    res.json(imageFile);
  })
})


app.use(bodyParser.urlencoded({ extended: true }));

app.post('/students/add', function(req, res) {
  data.addStudent(req.body)
  .then(res.redirect('/students'))
  .catch((err) => res.json({"message": err}))   
}) 


app.get("/students", function(req, res){
  if(req.query.status){
    data.getStudentsByStatus(req.query.status)
    .then(function(data){res.json(data);})
    .catch(function(err){res.send(err);})
  }
  else if(req.query.programCode){
    data.getStudentsByProgramCode(req.query.programCode)
    .then(function(data){res.json(data);})
    .catch(function(err){res.send(err);})
  }
  else if(req.query.credential){
    data.getStudentsByExpectedCredential(req.query.credential)
    .then(function(data){res.json(data);})
    .catch(function(err){res.send(err);})
  }
  else{
    data.getAllStudents().then(function(data){res.json(data);})
        .catch(function(err){res.send(err);})
  }    
}); 

app.get('/student/value', (req, res) => {
  data.getStudentsById(sid)
  .then((data) => {res.json(data);})
});

app.use((req, res) => {
  res.status(404).sendFile(path.join(__dirname,"/views/error.html"));
});



// setup http server to listen on HTTP_PORT
data.initialize().then(()=>{
  app.listen(HTTP_PORT, onHttpStart);
}).catch((err)=>{
console.log("There is no data",err)})

