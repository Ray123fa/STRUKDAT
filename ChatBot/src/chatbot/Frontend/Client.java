/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package chatbot.Frontend;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Muhammad Rayhan Faridh
 */
public class Client {
    public static void main(String args[]){
        String hostName = "localhost";
        int portNumber = 4444;
        try (
                Socket echoSocket = new Socket(hostName, portNumber);
                PrintWriter out = new PrintWriter(echoSocket.getOutputStream(),true);
                BufferedReader in = new BufferedReader(new InputStreamReader(echoSocket.getInputStream()));
                BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
        )
        {
            String msg;
            while((msg = stdIn.readLine()) != null)
            {
                out.println(msg);
                if(msg.equalsIgnoreCase("/exit")) break;
                System.out.println("Bot: "+ in.readLine());
            }
        } catch (IOException ex) {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
