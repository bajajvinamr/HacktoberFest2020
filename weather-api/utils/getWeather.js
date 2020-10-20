const { response } = require('express')
const request = require('request')
function getWeather(latitude,longitude,callback)
{
    const url = 'http://api.weatherstack.com/current?access_key=9aee4641467d9d36597044ee86f750b1&query='+latitude+','+longitude
    request({url,json:true},(error,response)=>{
        console.log(response.body.current)
        if(error)
        {
            callback('Could not connect to weather',undefined)
        }
        else if(response.body.error)
        {
            callback('Co-ordinates are wrong',undefined)
        }
        else{
            callback(undefined,response.body.current)
        }
    })
}

module.exports = getWeather