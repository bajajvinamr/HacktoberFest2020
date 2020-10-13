var firebaseConfig = {
    apiKey: "AIzaSyBWBKNk1XShVeneEVoTZ_l5maA4vNlJZHk",
    authDomain: "contactform-firebase-44b36.firebaseapp.com",
    databaseURL: "https://contactform-firebase-44b36.firebaseio.com",
    projectId: "contactform-firebase-44b36",
    storageBucket: "contactform-firebase-44b36.appspot.com",
    messagingSenderId: "243819155253",
    appId: "1:243819155253:web:2c37c8dce5eca4f177867c"
  };
  // Initialize Firebase
  firebase.initializeApp(firebaseConfig);

  //var messagesRef = firebase.database();
  var firestore = firebase.firestore();

  const db = firestore.collection("contactData");

document.getElementById("contactform").addEventListener("submit", submitform)
function submitform(e){
    e.preventDefault()
    
    var name = document.getElementById("name").value;
    var company = document.getElementById("company").value;
    var email = document.getElementById("email").value;
    var phone = document.getElementById("phone").value;
    var message = document.getElementById("message").value;
    
    saveMessage(name, message, phone, company, email);
}

//save message to firebase
function saveMessage(name, message, phone, company, email){
    db.doc().set({
        name: name,
        company: company,
        email: email,
        phone: phone,
        message: message
    })
    .then(function(){
        console.log("Data Saved");
    })
    .catch(function(error){
        console.log(error);
    });
}