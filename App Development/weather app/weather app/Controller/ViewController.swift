//
//  ViewController.swift
//  weather app
//
//  Created by Swamita on 29/05/20.
//  Copyright © 2020 Swamita. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITextFieldDelegate, weatherManagerDelegate {

    @IBOutlet weak var weatherSymbol: UIImageView!
    @IBOutlet weak var tempLabel: UILabel!
    @IBOutlet weak var cityLabel: UILabel!
    @IBOutlet weak var searchBar: UITextField!
    
    var wManager = weatherManager()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        searchBar.delegate = self
        wManager.delegate = self
    }

    @IBAction func searchPressed(_ sender: UIButton) {
        searchBar.endEditing(true)
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        searchBar.endEditing(true)
        return true
    }
    
    func textFieldShouldEndEditing(_ textField: UITextField) -> Bool {
        if textField.text != ""{
            return true
        }
        else{
            textField.placeholder = "Type name of city here"
            return false
        }
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        if let city = textField.text {
            wManager.fetchWeather(cityName: city)
        }
        textField.text = ""
    }
    
    func didUpdateWeather(weather: weatherModel){
        print(weather.temperature)
    }
}

