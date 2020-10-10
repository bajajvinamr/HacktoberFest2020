let mongoose = require('mongoose');

let userSchema = mongoose.Schema({
    fname:{
        type:String,
        required:true
    },
    lname:{
        type:String,
        required:true
    }
});

let Users = module.exports = mongoose.model('nemusers',userSchema);