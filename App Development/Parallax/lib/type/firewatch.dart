import 'package:flutter/material.dart';
import 'package:parallax/parallax.dart';

class FireWatch extends StatefulWidget {
  @override
  _FireWatchState createState() => _FireWatchState();
}

class _FireWatchState extends State<FireWatch> {
  double top0 = 0,
      top1 = 0,
      top2 = 0,
      top3 = 0,
      top4 = 0,
      top5 = 0,
      top6 = 0,
      top7 = 0,
      top8 = 0;

  double left = -660;
  String path = 'asset/firewatch';

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: NotificationListener(
        onNotification: (v) {
          if (v is ScrollUpdateNotification) {
            setState(() {
              top8 -= v.scrollDelta / 1;
              top7 -= v.scrollDelta / 1.5;
              top6 -= v.scrollDelta / 2;
              top5 -= v.scrollDelta / 2.5;
              top4 -= v.scrollDelta / 3;
              top3 -= v.scrollDelta / 3.5;
              top2 -= v.scrollDelta / 4;
              top1 -= v.scrollDelta / 4.5;
              top0 -= v.scrollDelta / 5;
            });
          }
        },
        child: Stack(
          children: [
            ParallaxImage(top: top0, url: '$path/parallax0', left: left),
            ParallaxImage(top: top1, url: '$path/parallax1', left: left),
            ParallaxImage(top: top2, url: '$path/parallax2', left: left),
            ParallaxImage(top: top3, url: '$path/parallax3', left: left),
            ParallaxImage(top: top4, url: '$path/parallax4', left: left),
            ParallaxImage(top: top5, url: '$path/parallax5', left: left),
            ParallaxImage(top: top6, url: '$path/parallax6', left: left),
            ParallaxImage(top: top7, url: '$path/parallax7', left: left),
            ParallaxImage(top: top8, url: '$path/parallax8', left: -600),
            ListView(
              children: [
                Container(
                  height: 560,
                  color: Colors.transparent,
                ),
                Container(
                  color: Color(0xff210002),
                  width: double.infinity,
                  padding: EdgeInsets.only(top: 80),
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Text('Parallax In',
                          style: TextStyle(
                              fontSize: 30,
                              letterSpacing: 1.3,
                              color: Color(0xffffaf00))),
                      SizedBox(height: 20),
                      Text('Flutter',
                          style: TextStyle(
                              fontSize: 55,
                              letterSpacing: 1.8,
                              color: Color(0xffffaf00))),
                      SizedBox(
                          width: 220,
                          height: 10,
                          child: Divider(height: 1, color: Color(0xffffaf00))),
                      SizedBox(height: 40),
                      FlatButton(
                        onPressed: (){
                          Navigator.pop(context);
                        },
                        child: Text(
                          'Try More',
                          style: TextStyle(
                              fontSize: 30,
                              letterSpacing: 1.3,
                              color: Color(0xffffaf00)),
                        ),
                      ),
                      SizedBox(height: 100),
                    ],
                  ),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
