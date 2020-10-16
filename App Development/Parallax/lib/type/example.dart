import 'package:flutter/material.dart';

class Example extends StatefulWidget {
  @override
  _ExampleState createState() => _ExampleState();
}

class _ExampleState extends State<Example> {
  
  double top1 = 250;
  double top2 = 300;
  double top3 = 350;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Try Scrolling Vertically'),
      ),
      body: NotificationListener(
        onNotification: (v) {
          if (v is ScrollUpdateNotification) {
            setState(() {
              top1 -= v.scrollDelta / 2;
              top2 -= v.scrollDelta / 1.5;
              top3 -= v.scrollDelta / 1;
            });
          }
        },
        child: Stack(
          children: <Widget>[
            Positioned(
              top: top1,
              left: 50,
              child: Container(
                height: 100,
                width: 100,
                color: Colors.red,
              ),
            ),
            Positioned(
              top: top2,
              left: 90,
              child: Container(
                height: 100,
                width: 100,
                color: Colors.purple,
              ),
            ),
            Positioned(
              top: top3,
              left: 220,
              child: Container(
                height: 100,
                width: 100,
                color: Colors.blue,
              ),
            ),
            ListView(
              children: <Widget>[
                Container(
                  height: 1500,
                  color: Colors.transparent,
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
