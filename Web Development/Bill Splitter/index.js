
document.getElementById("calculate").onclick = function() {
  calculateTip();
};

function calculateTip() {
  var billAmt = document.getElementById("amtbill").value;
  var addTip = document.getElementById("addTip").value;
  var numPeople = document.getElementById("numpeople").value;


  if (billAmt === "" || addTip == 0) {
    alert("Please enter values");
    return;
  }

  //Calculate bill splitting
  var billTotal = billAmt / numPeople;

  //Calculate tip amount
  var total = (billAmt * addTip) / numPeople;

  //calculate total
  var grandTotal = billTotal + total;

  //round to two decimal places
  total = Math.round(total * 100) / 100;
  billTotal = Math.round(billTotal * 100) / 100;
  grandTotal = Math.round(grandTotal * 100) / 100;

  //next line allows us to always have two digits after decimal point
  total = total.toFixed(2);
  billTotal = billTotal.toFixed(2);
  grandTotal = grandTotal.toFixed(2);


if (numPeople === "" || numPeople <= 1) {
  numPeople = 1;
 
} else {
    document.getElementById("split").innerHTML = billTotal;
}

  //Display the tip
    document.getElementById("tip").innerHTML = total;

//Display the Grand Totals
    document.getElementById("grand").innerHTML = grandTotal;
}


