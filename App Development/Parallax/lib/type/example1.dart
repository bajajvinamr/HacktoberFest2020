import 'package:flutter/material.dart';

class Example1 extends StatefulWidget {
  @override
  _Example1State createState() => _Example1State();
}

class _Example1State extends State<Example1> {
  
  double top1 = 180;
  double top2 = 200;
  double left = 0;

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
              left += v.scrollDelta/1;
            });
          }
        },
        child: Stack(
          children: <Widget>[
            Positioned(
              top: top1,
              left: 50,
              child: Container(
                height: 50,
                width: 50,
                color: Colors.red,
              ),
            ),
            Positioned(
              top: top2,
              left: 90,
              child: Container(
                height: 50,
                width: 50,
                color: Colors.purple,
              ),
            ),
            Positioned(
              top: 280,
              left: left,
              child: Container(
                height: 50,
                width: 50,
                color: Colors.blue,
              ),
            ),
            ListView(
              children: <Widget>[
                Container(
                  height: 700,
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
