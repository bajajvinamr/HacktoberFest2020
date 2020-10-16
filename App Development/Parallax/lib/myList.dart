import 'package:flutter/material.dart';
import 'package:parallax/type/example.dart';
import 'package:parallax/type/example1.dart';
import 'package:parallax/type/firewatch.dart';

class MyList extends StatefulWidget {
  @override
  _MyListState createState() => _MyListState();
}

class _MyListState extends State<MyList> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SafeArea(
        child: ListView(
          children: [
            MyCard(name: 'Example1',page: Example(),),
            MyCard(name: 'Example2', page: Example1(),),
            MyCard(name: 'Example3',page: FireWatch(),),
          ],
        ),
      ),
    );
  }
}

class MyCard extends StatelessWidget {
  
  final String name;
  final Widget page;

  const MyCard({
    Key key,
    this.page,
    this.name
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return FlatButton(
      onPressed: () {
        Navigator.push(context, MaterialPageRoute(builder: (context) => page));
      },
      child: Card(
        color: Colors.blue,
        child: Container(
          width: double.infinity,
          padding: EdgeInsets.all(30),
          child: Center(
            child: Text(
              name,
              style: TextStyle(
                fontSize: 30,
                color: Colors.white,
              ),
            ),
          ),
        ),
      ),
    );
  }
}
