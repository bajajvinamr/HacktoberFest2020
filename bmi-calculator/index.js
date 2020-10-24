function bmi() {
  const height = Number(document.querySelector('.height').value)
  const weight = Number(document.querySelector('.weight').value)
  const result = weight / (height * height)
  document.querySelector('.result').innerHTML = `Your bmi is: ${result}`
}
