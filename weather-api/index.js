const express = require('express')
const getWeather = require('./utils/getWeather')
const getLocation = require('./utils/getLocation')
const app = express()
//setup static files
app.use(express.static('./public'))

//setup routes
app.get('/',(req,res)=>{
        res.render('home.ejs')
})

app.get('/weather',(req,res)=>{
        const address = req.query.address
        getLocation(address,(error,[longitude,latitude]=[],place_name)=>{
                if(error)
                {
                        res.render('weather.ejs',{error})
                }
                else{
                       
                        getWeather(latitude,longitude,(error,{weather_icons,temperature,wind_speed,humidity}={})=>{
                                if(error)
                                {
                                        res.render('weather.ejs',{error})
                                }
                                else{
                                        places = place_name.split(',')
                                        error = undefined
                                        res.render('weather.ejs',{error,icon:weather_icons[0],temperature,humidity,wind_speed,place_name:places[0]})
                                }
                        })
                }
        })
})
const port = process.env.PORT||3000
app.listen(port,()=>{
        console.log('listening on port 5000')
})