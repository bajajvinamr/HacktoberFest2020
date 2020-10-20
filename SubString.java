import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class SubString
{
	JFrame frame = new JFrame("Count strings");
	JLabel label1 = new JLabel("Enter String:             ");
	JLabel label2 = new JLabel("Enter sub string:      ");
	JTextField f1 = new JTextField(15);
	JTextField f2 = new JTextField(15);
	JPanel pan = new JPanel();
	JButton btn = new JButton("Count SubString");
	JLabel res = new JLabel();
	public static void main(String[] args) {
		SubString s= new SubString();
		s.go();
	}
	public void go()
	{
		btn.addActionListener(new Btn());
		pan.setPreferredSize(new Dimension(400,200));
       pan.add(label1);
       pan.add(f1);
       pan.add(label2);
       pan.add(f2);
       pan.add(btn);
       frame.getContentPane().add(BorderLayout.EAST,pan);
       frame.getContentPane().add(BorderLayout.SOUTH,res);
       frame.setSize(400,200);
       frame.setVisible(true);
	}
	private class Btn implements ActionListener
	{
       public void actionPerformed(ActionEvent e)
       {
       	int count = perform();
       	res.setText("Occurence of "+f2.getText()+" in "+f1.getText()+" is "+count);
       }
	}
	private int perform()
	{
		int count=0;
		String s1 = f1.getText();
		String s2 = f2.getText();
		System.out.println(s1+"-----------------"+s2);

		// String[] str = s1.split(s2,-1).length-1;
		return s1.split(s2,-1).length-1;
	}


}