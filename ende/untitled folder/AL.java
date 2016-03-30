import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;
import javax.imageio.*;
import java.util.*;

public class AL extends Frame implements WindowListener,ActionListener {
    
    TextField text = new TextField(25);
    TextField pass = new TextField(4);
    Button en;
    Button de;
    JLabel pro;
    private int numClicks = 0;
    
    public static void main(String[] args) {
        AL myWindow = new AL("crypto");
        myWindow.setSize(300,300);
        /*myWindow.setVisible(true);
        try {
        myWindow.setContentPane(new JLabel(new ImageIcon(ImageIO.read(new File("test.jpg")))));
        } catch (Exception er)  {
            System.out.println(er);
        }
        myWindow.setResizeble(false);*/
        myWindow.setVisible(true);
    }
    
    
    public AL(String title) {
        
        super(title);
        setLayout(null);
        addWindowListener(this);
        
        JLabel lblNewLabel = new JLabel();
		lblNewLabel.setBounds(27, 40, 89, 14);
		lblNewLabel.setText("enter path :");
        
        text.setBounds(31, 68, 236, 24);
        
        JLabel lblNewLabel_1 = new JLabel();
		lblNewLabel_1.setBounds(31, 115, 89, 14);
		lblNewLabel_1.setText("enter pin :");

        pass.setBounds(167, 115, 64, 19);
        
        en = new Button("Encript");
        en.setBounds(31, 153, 100, 31);
        
        de = new Button("Decript");
        de.setBounds(167, 152, 100, 31);
        
        pro = new JLabel();
        pro.setBounds(70, 211, 162, 21);
        pro.setText("Click you option once and wait");
        
        add(lblNewLabel);
        add(lblNewLabel_1);
        add(text);
        add(pass);
        add(en);
        add(de);
        add(pro);
        
        en.addActionListener(this);
        de.addActionListener(this);
        
    }
    
    public void actionPerformed(ActionEvent e)  {
        
        try {
            java.io.File file = new java.io.File("file");
            if (!file.exists())   {
                throw
            }
            Runtime.getRuntime().exec("./file");
            
            if(e.getSource() == en) {
                pro.setText("Encripting file");
                Runtime.getRuntime().exec("./en 1 " + text.getText() +" "+pass.getText());
                
            }   else    {
                pro.setText("Decripting file");
                Runtime.getRuntime().exec("./en 0 " + text.getText() +" "+pass.getText());
            }
            
        } catch (Exception er)  {
            System.out.println(er+" at actionListener");
        }
        
        try {
            Thread.sleep(1000);
            java.io.File infile = new java.io.File(".progress.dat");
            Scanner input = new Scanner(infile);
            if(input.hasNext()) {
                pro.setText(input.nextLine());
            }   else    {
                pro.setText("system error");
            }
            input.close();
            Runtime.getRuntime().exec("./file");
        } catch (Exception er)  {
            System.out.println(er+" at file response");
        }
        
    }
    
    public void windowClosing(WindowEvent e) {
        dispose();
        System.exit(0);
    }
    
    //not used
    public void windowOpened(WindowEvent e) {}
	public void windowClosed(WindowEvent e) {}
	public void windowIconified(WindowEvent e) {}
	public void windowDeiconified(WindowEvent e) {}
	public void windowActivated(WindowEvent e) {}
	public void windowDeactivated(WindowEvent e) {}
    
}

