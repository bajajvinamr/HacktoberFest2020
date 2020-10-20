import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.util.*;
import javax.sound.midi.*;
public class Sound 
{
    ArrayList<String> arr = new ArrayList<>();
    JFrame frame = new JFrame();
    JTextArea display = new JTextArea(2,3);
    JScrollPane sc = new JScrollPane(display);
    Font font = new Font("serif",Font.BOLD,30);
    Font fN = new Font("serif",Font.PLAIN,30);
    Color color = new Color(16, 42, 59);
    static Sequencer sequencer;
    JButton btn7 = new JButton("7");
    JButton btn8 = new JButton("8");
    JButton btn9 = new JButton("9");
    JButton btnd = new JButton("/");
    JButton btn4 = new JButton("4");
    JButton btn5 = new JButton("5");
    JButton btn6 = new JButton("6");
    JButton btnm = new JButton("x");
    JButton btn1 = new JButton("1");
    JButton btn2 = new JButton("2");
    JButton btn3 = new JButton("3");
    JButton btns = new JButton("-");
    JButton btnc = new JButton("C");
    JButton btn0 = new JButton("0");
    JButton btne = new JButton("=");
    JButton btna = new JButton("+");
    JButton btnb1 = new JButton("(");
    JButton btnb2 = new JButton(")");
    JButton btnr = new JButton("B");
    JButton btnex = new JButton("^");
    JPanel panel = new JPanel();    
    public static void main(String[] args) {
        Sound start = new Sound();
        start.go();
    }
    public void go()
    {
    sc.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_NEVER);
    sc.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_ALWAYS);
    Dimension d = new Dimension(70,70);
    btn7.setPreferredSize(d);
    btn8.setPreferredSize(d);
    btn9.setPreferredSize(d);
    btnd.setPreferredSize(d);
    btn4.setPreferredSize(d);
    btn5.setPreferredSize(d);
    btn6.setPreferredSize(d);
    btnm.setPreferredSize(d);
    btn1.setPreferredSize(d);
    btn2.setPreferredSize(d);
    btn3.setPreferredSize(d);
    btns.setPreferredSize(d);
    btnc.setPreferredSize(d);
    btn0.setPreferredSize(d);
    btne.setPreferredSize(d);
    btna.setPreferredSize(d);
    btnb1.setPreferredSize(d);
    btnb2.setPreferredSize(d);
    btnex.setPreferredSize(d);
    btnr.setPreferredSize(d);
        frame.setResizable(false);
        btn7.setFont(font);
        btn8.setFont(font);
        btn9.setFont(font);
        btnd.setFont(font);
        btn4.setFont(font);
        btn5.setFont(font);
        btn6.setFont(font);
        btnm.setFont(font);
        btn1.setFont(font);
        btn2.setFont(font);
        btn3.setFont(font);
        btns.setFont(font);
        btnc.setFont(font);
        btn0.setFont(font);
        btne.setFont(font);
        btna.setFont(font);
        btnb1.setFont(font);
        btnb2.setFont(font);
        btnex.setFont(font);
        btnr.setFont(font);
        btn1.setBackground(color);
        btn1.setForeground(Color.white);
        btn2.setBackground(color);
        btn2.setForeground(Color.white);
        btn3.setBackground(color);
        btn3.setForeground(Color.white);
        btn4.setBackground(color);
        btn4.setForeground(Color.white);
        btn5.setBackground(color);
        btn5.setForeground(Color.white);
        btn6.setBackground(color);
        btn6.setForeground(Color.white);
        btn7.setBackground(color);
        btn7.setForeground(Color.white);
        btn8.setBackground(color);
        btn8.setForeground(Color.white);
        btn9.setBackground(color);
        btn9.setForeground(Color.white);
        btn0.setBackground(color);
        btn0.setForeground(Color.white);
        panel.add(btn7);
        panel.add(btn8);
        panel.add(btn9);
        panel.add(btnd);
        panel.add(btn4);
        panel.add(btn5);
        panel.add(btn6);
        panel.add(btnm);
        panel.add(btn1);
        panel.add(btn2);
        panel.add(btn3);
        panel.add(btns);
        panel.add(btnc);
        panel.add(btn0);
        panel.add(btne);
        panel.add(btna);
        panel.add(btnb1);
        panel.add(btnb2);
        panel.add(btnex);
        panel.add(btnr);
        Color cc = new Color(44, 44, 48);
        panel.setBackground(cc);
        frame.getContentPane().add(panel);
        frame.getContentPane().add(BorderLayout.NORTH,sc);
        frame.setSize(320,515);
        frame.setVisible(true);
        display.setFont(fN);
        display.setBackground(color);
        display.setForeground(Color.white);

        display.setEditable(false);
    btn1.addActionListener(new Btn1());    
    btn2.addActionListener(new Btn2());
    btn3.addActionListener(new Btn3());
    btn4.addActionListener(new Btn4());
    btn5.addActionListener(new Btn5());
    btn6.addActionListener(new Btn6());
    btn7.addActionListener(new Btn7());
    btn8.addActionListener(new Btn8());
    btn9.addActionListener(new Btn9());
    btn0.addActionListener(new Btn0());
    btna.addActionListener(new Btna());
    btnc.addActionListener(new Btnc());
    btns.addActionListener(new Btns());
    btnm.addActionListener(new Btnm());
    btnd.addActionListener(new Btnd());
    btne.addActionListener(new Btne());
    btnb1.addActionListener(new Btnb1());
    btnb2.addActionListener(new Btnb2());
    btnex.addActionListener(new Btnex());
    btnr.addActionListener(new Btnr());
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
    public void call()
    {
          try
        {
        sequencer = MidiSystem.getSequencer();
        sequencer.open();
        Sequence seq = new Sequence(Sequence.PPQ, 4);
        Track track = seq.createTrack();
        ShortMessage s1 = new ShortMessage();
        s1.setMessage(192,1,10,0);
        MidiEvent m1 = new MidiEvent(s1,0);
        track.add(m1);
        ShortMessage s2 = new ShortMessage();
        s2.setMessage(144,1,100,100);
        MidiEvent m2 = new MidiEvent(s2,1);
        track.add(m2);
        ShortMessage s3 = new ShortMessage();
        s3.setMessage(128,1,66,0);
        MidiEvent m3 = new MidiEvent(s3,5);
        track.add(m3);
        sequencer.setSequence(seq);
        sequencer.start();

        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
    class Btn1 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));
            call();
        }
    }
    class Btn2 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));
             call();
        }
    }
    class Btn3 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));
            call();
        }
    }
    class Btn4 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));
            call();
        }
    }
    class Btn5 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));    
            call();        
        }
    }
    class Btn6 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));
            call();

        }
    }
    class Btn7 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));
            call();

        }
    }
    class Btn8 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));
            call();

        }
    }
    class Btn9 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));
            call();

        }
    }
    class Btna implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));

        }
    }
    class Btne implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            if(arr.size()>0)
               display.setText(Double.toString(new Inner().print()));
            arr.clear();
        }
    }
    class Btns implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));

        }
    }
    class Btnd implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));

        }
    }
    class Btnc implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.setText("");
            arr.clear();
        }
    }
    class Btnm implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add(e.getActionCommand());

        }
    }
    class Btn0 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));
            call();

        }
    }
     class Btnb1 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));
        }
    }
     class Btnb2 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));

        }
    }
     class Btnex implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            display.append(e.getActionCommand());
            arr.add((e.getActionCommand()));

        }
    }
     class Btnr implements ActionListener
    {
       public void actionPerformed(ActionEvent e)
       {
        display.setText("");
        if(arr.size()>=1)
        {
         arr.remove(arr.size()-1);
         for(Object i:arr)
         {
          display.append((String)i);
         }
        }
        
       }
    }
    class Inner
    {
      String[] stack;
      String[] infix;
      String[] postfix;
      int top;
      public double print()
      {
        String strin="";
        boolean ff = true;
        ArrayList<String> arrstr = new ArrayList<>();
        ArrayList<String> finals = new ArrayList<>();
        for(int i=0;i<arr.size();i++)
        {
           strin = strin+arr.get(i);
        }
        String[] splitt= strin.split("[(^+-/x)]");
        for(int i=0;i<splitt.length;i++)
        {
            if(!(splitt[i].isEmpty()))
                arrstr.add(splitt[i]);
        }
        int n=0,t=0;
        for(int i=0;i<arr.size();i++)
        {
            if(Character.isDigit(arr.get(i).charAt(0))&&ff)
            {
                 finals.add(n,arrstr.get(t));
                 n++;
                 t++;
                 ff=false;
            }
            else if(!(Character.isDigit(arr.get(i).charAt(0))))
            {
                finals.add(n,arr.get(i));
                ff=true;
                n++;
            }
        }        
        stack=new String[finals.size()];
        infix=new String[finals.size()];
        postfix=new String[finals.size()];
        top=-1;
        int j=0;
        for(int i=0;i<infix.length;i++)
        {
            infix[i]=(finals.get(i));
        }
        push("#");
        for(int i=0;i<infix.length;i++)
        {
           Boolean flag = Character.isDigit(infix[i].charAt(0));
           if(flag)
           {
            postfix[j]=infix[i];
            j++;
           }
           else if(infix[i].equals("("))
           {
             push(infix[i]);
           }
           else if(infix[i].equals(")"))
           {
            while(!(stack[top].equals("(")))
            {
                postfix[j]=pop();
                j++;
            }
            String ch = pop();
           }
           else
           {
            while(stkPrecedence(stack[top])>=infixPrecedence(infix[i]))
            {
                postfix[j]=pop();
                j++;
            }
            push(infix[i]);
           } 
        }
        while(!(stack[top].equals("#")))
        {
            postfix[j]=pop();
            j++;
        }
        double result = new InnerCheck().checkresult(postfix);
        return result;
      }
      public void push(String i)
      {
        top++;
        stack[top]=i;
      }
      public String pop()
      {
        String i = stack[top];
        top--;
        return i;
      }
      public int stkPrecedence(String i)
      {
        int ret=0;
        switch(i)
        {
            case "#" : ret=0;break;
            case "(" : ret=0;break;
            case "+" : ret=2;break;
            case "-" :ret=2;break;
            case "x" : ret=4;break;
            case "/" : ret=4;break;
            case "^" : ret=5;break;
        }
        return ret;
      }
       public int infixPrecedence(String i)
      {
        int ret=0;
        switch(i)
        {
            case "#" : ret=0;break;
            case "(" : ret=0;break;
            case "+" : ret=1;break;
            case "-" : ret=1;break;
            case "x" : ret=3;break;
            case "/" : ret=3;break;
            case "^" : ret=6;break;
        }
        return ret;
      }
      class InnerCheck
      {
      double[] stk;
      public double checkresult(String[] postarr)
      {
        stk=new double[postarr.length];
        top=-1;
        double res=0,o1=0,o2=0;
        for(int i=0;i<postarr.length;i++)
        {
          if(postarr[i]!=null)
          {
          Boolean flag = Character.isDigit(postarr[i].charAt(0));
          if(flag)
          {
              pushit(Double.parseDouble(postarr[i]));
          }
          else
          {
            try{
               o1 = popout();
               o2 = popout();
            }
            catch(NumberFormatException ex)
            {
                display.setText("HIGH LIMIT");
            }
            
            switch(postarr[i])
            {
                case "+" : pushit(o2+o1);break;
                case "-" : pushit(o2-o1);break;
                case "x" : pushit(o2*o1);break;
                case "/" : pushit(o2/o1);break;
                case "^" : pushit((int)(Math.pow(o2,o1)));break; 
            }
          }
          }
        }
        res=stk[0];
        return res;
      }
      public void pushit(double a)
      {
        top++;
        stk[top]=a;
      } 
      public double popout() throws NumberFormatException
      {
        double ele = stk[top];
        top--;
        return ele;
      }
      }
      }
      }      