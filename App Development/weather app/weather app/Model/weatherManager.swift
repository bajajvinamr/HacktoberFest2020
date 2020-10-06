//
//  weatherManager.swift
//  weather app
//
//  Created by Swamita on 29/05/20.
//  Copyright © 2020 Swamita. All rights reserved.
//

import Foundation

protocol weatherManagerDelegate {
    func didUpdateWeather(weather: weatherModel)
    
}

struct weatherManager{
    let weatherAPI = "https://api.openweathermap.org/data/2.5/weather?appid=7703b6c6f6590a087f4f58a20562de09&units=metric"
    
    var delegate: weatherManagerDelegate?
    
    func fetchWeather(cityName: String){
        let URLString = "\(weatherAPI)&q=\(cityName)"
        performRequest(urlString: URLString)
    }
    
    func performRequest (urlString: String){
        if let url = URL(string: urlString){
            let session = URLSession(configuration: .default)
            let task = session.dataTask(with: url) { (data, response, error) in
                if error != nil {
                    print(error!)
                    return
                }
                if let safeData = data{
                    //let dataString = String(data: safeData, encoding: .utf8)
                    //print(dataString)
                    if let weather = self.parseJSON(weatherData: safeData){
                        self.delegate?.didUpdateWeather(weather: weather)
                    }
                }
            }
            task.resume()
        }
    }
    
    func parseJSON(weatherData: Data)-> weatherModel?{
        let decoder = JSONDecoder()
        do {
            let decodedData = try decoder.decode(WeatherData.self, from: weatherData)
            let id = decodedData.weather[0].id
            let name = decodedData.name
            let temp = decodedData.main.temp
            let weather = weatherModel(conditionId: id, cityName: name, temperature: temp)
            return weather
            
        }catch{
            print(error)
            return nil
        }
    }
    
    
}

