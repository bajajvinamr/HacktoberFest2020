const express = require('express');
const path = require('path');
var mongoose = require('mongoose');
const bodyParser = require('body-parser');

// Mongodb connection with deprecations removed
mongoose.connect('mongodb://localhost/nemdb',{useNewUrlParser: true ,useUnifiedTopology: true });
let db = mongoose.connection;

// Db connected
db.once('open',()=>{
    console.log('Connected to MongoDB - nemdb');
});

// Db errors 
db.on('error',(err)=>{
    console.log(err);
});

const app = express();
const { urlencoded } = require('body-parser');
//Body Parser middleware
app.use(bodyParser.urlencoded({extended:false}));
//Parse application json
app.use(bodyParser.json());

// Import Schema
let Users = require('./models/users');

// Setting views for website and view engine
app.set('views',path.join(__dirname,'views'));
app.set('view engine','ejs');


// Main Page rendering
app.get('/',(req,res)=>{
    
    Users.find({},(err,users)=>{
        if(err){
            throw(err);
        }
        else{
            res.render('pages/index',{
                users:users
            });
        }
    });
})

// Add Page rendering
app.get('/adduser',(req,res)=>{
    res.render('pages/adduser');
});


// Add Page POST 
app.post('/adduser',(req,res)=>{
    let user = new Users();
    user.fname = req.body.fname;
    user.lname = req.body.lname;
    
    user.save((err)=>{
        if(err){
            throw(err);
        }else{
            res.redirect('/');
        }
    })
});

// Delete page rendering
app.get('/deluser',(req,res)=>{
    res.render('pages/deluser');
});


// Delete page POST
app.post('/deluser',(req,res)=>{
    Users.find({},(err,users)=>{
        if(err){
            throw(err);
        }
        else{
            users.forEach((user)=>{
                if(user.fname===req.body.fname && user.lname===req.body.lname){
                    Users.deleteOne({fname:req.body.fname,lname:req.body.lname},(err)=>{
                        if(err){
                            throw(err);
                        }
                        else{
                            console.log("Successfully deleted " + req.body.fname + " " + req.body.lname);
                        }
                    });
                }
            });
            res.redirect('/');
        }
    });
});

app.get('/update/:id',(req,res)=>{
    Users.findById(req.params.id,(err,users)=>{
        if(err){
            throw(err);
        }
        else{
            res.render('pages/edit_user',{
                users:users,
            });
        }
    });

});

app.post('/update/:id',(req,res)=>{
    let user = {};
    user.fname = req.body.fname;
    user.lname = req.body.lname;
    
    let query  ={_id:req.params.id}

    Users.update(query,user,(err)=>{
        if(err){
            throw(err);
        }else{
            console.log(user)
            res.redirect('/');
        }
    })
});

app.listen(3000,()=>{
    console.log('Server running at port:3000');
})