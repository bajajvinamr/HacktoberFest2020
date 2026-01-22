import 'package:flutter/material.dart';
import 'package:flutter/painting.dart';
import 'package:flutter_swarm_game/game_controller.dart';

class ScoreText {
  final GameController gameController;
  TextPainter painter;
  Offset position;

  ScoreText(this.gameController) {
    painter = TextPainter(
      textAlign: TextAlign.center,
      textDirection: TextDirection.ltr,
    );
    position = Offset.zero;
  }

  void render(Canvas c) {
    painter.paint(c, position);
  }

  void update(double t) {
    if ((painter.text ?? '') != gameController.score.toString()) {
      painter.text = TextSpan(
        text: gameController.score.toString(),
        style: TextStyle(
          color: Colors.black,
          fontSize: 70.0,
        ),
      );
      painter.layout();

      position = Offset(
        (gameController.screenSize.width / 2) - (painter.width / 2),
        (gameController.screenSize.height * 0.2) - (painter.height / 2),
      );
    }
  }
}