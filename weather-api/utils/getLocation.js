const request = require('request')
function getLocation(address,callback){
    const url = `https://api.mapbox.com/geocoding/v5/mapbox.places/${address}.json?access_token=pk.eyJ1Ijoic2FudGVjaCIsImEiOiJja2Z6bXBmaHYyOTA2MnJzOG1iZWIzYnQxIn0.ZzBfghVpYVmT208Pnb9QRQ`
    request({url,json:true},(err,response)=>{
        console.log(response.body.features)
        if(err)
        {
            callback('Could not connect to weather',undefined)
        }
        else if(!response.body.features||response.body.features.length === 0)
        {
            callback('Search correct place again',undefined)
        }
        else{

            callback(undefined,response.body.features[0].center,response.body.features[0].place_name)
        }
    })
}

module.exports = getLocation