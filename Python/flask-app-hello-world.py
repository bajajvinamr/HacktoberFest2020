from flask import Flask, url_for
app = Flask(__name__)

@app.route("/hello/")
def hello():
    return "<h1>Hello World!</h1>"

if __name__ == "__main__":
    with app.test_request_context():
        print(url_for('hello'))
    # app.run(host="0.0.0.0", port="8080")
