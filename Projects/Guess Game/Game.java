/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author samad
 */
public class Game {

    static boolean game(int Try, int lives, String s, int temp[]) {
        Random r = new Random();
        Scanner in = new Scanner(System.in);
        String input;
        switch (Try) {
            case 1:

                System.out.println("Remaing lives are " + lives);
                for (char c : s.toCharArray()) {
                    System.out.print("_\t");
                }
                System.out.println("\nEnter your answere");
                input = in.next();
                if (input.equalsIgnoreCase(s)) {
                    return true;
                } else {
                    return false;
                }
            case 2:
                System.out.println("Let's give it another try");
                System.out.println("Remaing lives are " + lives);
                temp[0] = r.nextInt(s.length());
                for (int i = 0; i < s.length(); i++) {
                    if (i == temp[0]) {

                        System.out.print(s.charAt(i) + "\t");
                    } else {
                        System.out.print("_\t");
                    }

                }

                System.out.println("\nEnter your answere");
                input = in.next();
                if (input.equalsIgnoreCase(s)) {
                    return true;
                } else {
                    return false;
                }

            case 3:
                System.out.println("Let's give it another try");
                System.out.println("Remaing lives are " + lives);
                temp[1] = r.nextInt(s.length());
                while (temp[1] == temp[0]) {
                    temp[1] = r.nextInt(s.length());
                }
                for (int i = 0; i < s.length(); i++) {
                    if (i == temp[1] || i == temp[0]) {

                        System.out.print(s.charAt(i) + "\t");
                    } else {
                        System.out.print("_\t");
                    }

                }
                System.out.println("\nEnter your answere");
                input = in.next();
                if (input.equalsIgnoreCase(s)) {
                    return true;
                } else {
                    return false;
                }

            case 4:

                System.out.println("Let's give it another try");
                System.out.println("Remaing lives are " + lives);
                temp[2] = r.nextInt(s.length());
                while (temp[2] == temp[0] || temp[2] == temp[1]) {
                    temp[2] = r.nextInt(s.length());
                }
                for (int i = 0; i < s.length(); i++) {
                    if (i == temp[0] || i == temp[1] || i == temp[2]) {

                        System.out.print(s.charAt(i) + "\t");
                    } else {
                        System.out.print("_\t");
                    }

                }

                System.out.println("\nEnter your answere");
                input = in.next();
                if (input.equalsIgnoreCase(s)) {
                    return true;
                } else {
                    return false;
                }

            case 5:

                System.out.println("Let's give it another try");
                System.out.println("Remaing lives are " + lives);
                temp[3] = r.nextInt(s.length());
                while (temp[3] == temp[0] || temp[3] == temp[1] || temp[3] == temp[2]) {
                    temp[3] = r.nextInt(s.length());
                }
                for (int i = 0; i < s.length(); i++) {
                    if (i == temp[0] || i == temp[1] || i == temp[2] || i == temp[3]) {

                        System.out.print(s.charAt(i) + "\t");
                    } else {
                        System.out.print("_\t");
                    }

                }

                System.out.println("\nEnter your answere");
                input = in.next();
                if (input.equalsIgnoreCase(s)) {
                    return true;
                } else {
                    return false;
                }
            case 6:
                System.out.println("Let's give it another try");
                System.out.println("Remaing lives are " + lives);
                temp[4] = r.nextInt(s.length());
                while (temp[4] == temp[0] || temp[4] == temp[1] || temp[4] == temp[2] || temp[4] == temp[3]) {
                    temp[4] = r.nextInt(s.length());
                }
                for (int i = 0; i < s.length(); i++) {
                    if (i == temp[0] || i == temp[1] || i == temp[2] || i == temp[3] || i == temp[4]) {

                        System.out.print(s.charAt(i) + "\t");
                    } else {
                        System.out.print("_\t");
                    }

                }

                System.out.println("\nEnter your answere");
                input = in.next();
                if (input.equalsIgnoreCase(s)) {
                    return true;
                } else {
                    return false;
                }

//                break;
            default:
                throw new AssertionError();
        }
//        return false;

    }

    public static void main(String[] args) {
        String[] words = {"water", "cloth", "table", "solider", "chrome", "navigate", "random", "string", "eight", "bottle", "website", "military"};
        Random r = new Random();
        String s = words[r.nextInt(words.length)];
        Scanner in = new Scanner(System.in);
        String input;
        int[] temp = new int[10];

        int lives, Try = 0;
        switch (s.length()) {
            case 5:

                lives = 2;
                Try++;

                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;

                }

                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    System.out.println("You have lost");
                    for (char c : s.toCharArray()) {
                        System.out.print(c + "\t");
                    }
                }

                break;

            case 6:

                lives = 3;
                Try++;
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    System.out.println("You have lost");
                    for (char c : s.toCharArray()) {
                        System.out.print(c + "\t");
                    }
                }

                break;
            case 7:

                lives = 4;
                Try++;
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    System.out.println("You have lost");
                    for (char c : s.toCharArray()) {
                        System.out.print(c + "\t");
                    }
                }

                break;
            case 8:

                lives = 5;
                Try++;
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    lives--;
                    Try++;
                }
                if (game(Try, lives, s, temp)) {
                    System.out.println("Right!!! You won");
                    break;
                } else {
                    System.out.println("You have lost");
                    for (char c : s.toCharArray()) {
                        System.out.print(c + "\t");
                    }
                }

                break;
            default:
                throw new AssertionError();

        }
    }

}
