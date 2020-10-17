'''
script called weather that return the environmental parameters (temperature (min, max), windspeed, humidity, cloud, pressure, sunrise and sunset) of any location you want; 
after passing arguments (like user api and city id).

This project requires your personal api key for the OpenWeatherMap.. Just have a look into and enjoy

For the given location it gives the relevant details
'''
import datetime
import json
import urllib.request


def cityname_url(api_key, city_name):
    base_url = 'http://api.openweathermap.org/data/2.5/weather?q='
    temp_unit = 'metric'
    complete_url = base_url + str(city_name) + '&mode=json&units=' + temp_unit + '&appid=' + api_key
    return complete_url


def citycode_url(api_key, city_code):
    base_url = 'http://api.openweathermap.org/data/2.5/weather?id='
    temp_unit = 'metric'
    complete_url = base_url + str(city_code) + '&mode=json&units=' + temp_unit + '&appid=' + api_key
    return complete_url


def time_converter(time):
    converted_time = datetime.datetime.fromtimestamp(int(time)).strftime('%I:%M %p')
    return converted_time


def fetch_raw_data(name_url):
    with urllib.request.urlopen(name_url) as url:
        raw_data = json.loads(url.read().decode('utf-8'))
    return raw_data


def process_Data(raw_weather_data):
    process_dict = {}
    main = raw_weather_data.get('main')
    sys = raw_weather_data.get('sys')
    process_dict['City Name'] = raw_weather_data.get('name')
    process_dict['Country'] = sys.get('country')
    process_dict['Current Temperature'] = main.get('temp')
    process_dict['Temperature Min'] = main.get('temp_min')
    process_dict['Temperature Max'] = main.get('temp_max')
    process_dict['Wind'] = raw_weather_data.get('wind').get('speed')
    process_dict['Wind Degree'] = raw_weather_data.get('wind').get('deg')
    process_dict['Humidity'] = main.get('humidity')
    process_dict['Cloudiness'] = raw_weather_data.get('clouds').get('all')
    process_dict['Pressure'] = main.get('pressure')
    process_dict['Sunrise at'] = time_converter(sys.get('sunrise'))
    process_dict['Sunset at'] = time_converter(sys.get('sunset'))
    process_dict['Sky'] = raw_weather_data['weather'][0]['main']
    process_dict['dt'] = time_converter(raw_weather_data.get('dt'))
    return process_dict



def display_formatted_data(processed_data):
    temp_degree = '\xb0' + 'C'  # for °C
    print('------------------------------------------------------------------------------------------------------------')
    print("Weather report for the given location:")
    print('Requested location is - {}, {}'.format(processed_data['City Name'], processed_data['Country']))
    current_temp_unit = str(processed_data['Current Temperature']) + temp_degree
    print('Current Temperature: {}'.format(current_temp_unit))
    temp_min_unit = str(processed_data['Temperature Min']) + temp_degree
    print('Temperature min: {}'.format(temp_min_unit))
    temp_max_unit = str(processed_data['Temperature Max']) + temp_degree
    print('Temperature max: {}'.format(temp_max_unit))
    print('Wind Speed: {}, Degree: {}'.format(processed_data['Wind'], processed_data['Wind Degree']))
    print('Humidity: {}'.format(processed_data['Humidity']))
    print('Cloud: {}'.format(processed_data['Cloudiness']))
    print('Pressure: {}'.format(processed_data['Pressure']))
    print('Sunrise at: {}'.format(processed_data['Sunrise at']))
    print('Sunset at: {}'.format(processed_data['Sunset at']))
    print('Sky: {}'.format(processed_data['Sky']))
    print('Last update from the server: {}'.format(processed_data['dt']))
    print('------------------------------------------------------------------------------------------------------------')


if __name__ == '__main__':
    print("...Welcome to the weather info...")
    print("API Provided by OpenWeatherMap::::credits")
    try:
        api_key = input("Please enter your api_key for getting weather info:")
        print("Choose your choice how you want to search city")
        choice = int(input("1. By City name\n2. By City code\n"))
        if choice == 1:
            city_name = input("Enter the city name:")
            print("Processing...")
            name_url = cityname_url(api_key, city_name)
            raw_data = fetch_raw_data(name_url)

        else:
            city_code = input("Enter the city code:")
            print("Processing...")
            code_url = citycode_url(api_key, city_code)
            raw_data = fetch_raw_data(code_url)

        processed_data = process_Data(raw_data)

        display_formatted_data(processed_data)

    except:
        print("There was a problem. Please check either your API key, location or your internet connection.")
