//
//  weatherData.swift
//  weather app
//
//  Created by Swamita on 29/05/20.
//  Copyright © 2020 Swamita. All rights reserved.
//

import Foundation
struct WeatherData: Codable {
    let weather: [Weather]
    let main: Main
    let name: String
}

struct Main: Codable{
    let temp: Double
}

struct Weather: Codable{
    let description: String
    let id: Int
}
