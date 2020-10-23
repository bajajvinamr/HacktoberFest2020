/**
 * Created by rishabhshukla on 09/03/17.
 */


const express = require("express");
const bodyParser = require("body-parser");
const app = express();
const shortner = require("./shortner");
const port = 4100;

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended:true}))
app.use(express.static("static"));

app.get('/:shortcode',(req,res) => {

    shortner.expand(req.params.shortcode)
        .then((url) => {
            res.redirect(url);
        })
        .catch((error) => {

        });
});

app.post('/api/v1/shorten', (req, res) => {

    let url = req.body.url;
    let shortcode = shortner.shorten(url);
    res.send(shortcode);

});

app.get('/api/v1/expand/:shortcode', (req, res) => {

    let shortcode = req.body.shortcode;
    let url = url.expand(shortcode);
    res.send(url);

});

app.listen(port, () => {

    console.log("Listening on port "+port);

});

//console.log(shortner.shorten('http://google.com'));