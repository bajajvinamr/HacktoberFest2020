package com.company;

import java.util.*;

public class Linked {
    private static LinkedList<Integer> list = new LinkedList<>();
    //tampil data
    public static void tampilData(){
        ListIterator<Integer> iterator = list.listIterator();
        while (iterator.hasNext()){
            Integer integer = (Integer) iterator.next();
            System.out.print(integer);
        }
    }
    //tampil desc
    public static void tampilDesc(){
        Iterator<Integer> iterator = list.descendingIterator();
        while (iterator.hasNext()){
            Integer integer = (Integer) iterator.next();
            System.out.print(integer);
        }
    }
    public static void main(String[] args){
        list.add(7);
        list.add(3);
        list.add(5);
        list.add(1);
        tampilData();

        System.out.println();
        list.addFirst(1);
        //colections
        tampilData();
        System.out.println();
        list.addLast(7);
        //
        tampilData();
        System.out.println();
        list.removeFirst();
        //colections
        tampilData();
        System.out.println();
        list.removeLast();
        //colections
        tampilData();
        System.out.println();
        Collections.sort(list);
        //colections
        tampilData();
        System.out.println();
        System.out.println("Input data yang akan di hapus : ");
        Scanner input = new Scanner(System.in);
        int index = input.nextInt();
        for (int i = 0; i < list.size() ; i++){
            if (list.get(i) == index){
                list.remove(i);
                System.out.println("Data Berhasil Dihapus");
                break;
            }
        }
        System.out.println("data yang ada setelah di hapus");
        tampilData();
    }
}