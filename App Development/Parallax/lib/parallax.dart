import 'package:flutter/material.dart';

class ParallaxImage extends StatelessWidget {
  final double top;
  final String url;
  final double left;

  ParallaxImage({
    Key key,
    @required this.top,
    @required this.url,
    @required this.left,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Positioned(
      left: left,
      top: top,
      child: Container(
        width: 2000,
        child: Image.asset(
          "$url.png",
          fit: BoxFit.cover,
        ),
      ),
    );
  }
}
