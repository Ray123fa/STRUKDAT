/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package praweek10;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.filechooser.FileNameExtensionFilter;

/**
 *
 * @author Muhammad Rayhan Faridh
 */
public class Notes extends javax.swing.JFrame {

	/**
	 * Creates new form Notes
	 */
	public Notes() {
		initComponents();
	}

	/**
	 * This method is called from within the constructor to initialize the form.
	 * WARNING: Do NOT modify this code. The content of this method is always
	 * regenerated by the Form Editor.
	 */
	@SuppressWarnings("unchecked")
	// <editor-fold defaultstate="collapsed" desc="Generated
	// Code">//GEN-BEGIN:initComponents
	private void initComponents() {

		jScrollPane1 = new javax.swing.JScrollPane();
		contentTextArea = new javax.swing.JTextArea();
		prosesButton = new javax.swing.JButton();
		clearButton = new javax.swing.JButton();
		saveProsesButton = new javax.swing.JButton();
		jLabel1 = new javax.swing.JLabel();
		jLabel2 = new javax.swing.JLabel();
		jmlKarakterTextField = new javax.swing.JTextField();
		jmlBarisTextField = new javax.swing.JTextField();
		jmlVokalTextField = new javax.swing.JTextField();
		jmlKonsonanTextField = new javax.swing.JTextField();
		jLabel3 = new javax.swing.JLabel();
		jLabel4 = new javax.swing.JLabel();
		jMenuBar1 = new javax.swing.JMenuBar();
		jMenu1 = new javax.swing.JMenu();
		openMenuItem = new javax.swing.JMenuItem();
		saveMenuItem = new javax.swing.JMenuItem();

		setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

		contentTextArea.setColumns(20);
		contentTextArea.setLineWrap(true);
		contentTextArea.setRows(5);
		jScrollPane1.setViewportView(contentTextArea);

		prosesButton.setText("Proses Text");
		prosesButton.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				prosesButtonActionPerformed(evt);
			}
		});

		clearButton.setText("Clear Text Area");
		clearButton.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				clearButtonActionPerformed(evt);
			}
		});

		saveProsesButton.setText("Save Proses Text (*.txt)");
		saveProsesButton.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				saveProsesButtonActionPerformed(evt);
			}
		});

		jLabel1.setText("Jumlah Karakter (diluar spasi) :");

		jLabel2.setText("Jumlah Baris :");

		jLabel3.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
		jLabel3.setText("Jumlah Huruf Vokal :");

		jLabel4.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
		jLabel4.setText("Jumlah Huruf Konsonan :");

		jMenu1.setText("File");

		openMenuItem.setText("Open (*.txt)");
		openMenuItem.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				openMenuItemActionPerformed(evt);
			}
		});
		jMenu1.add(openMenuItem);

		saveMenuItem.setText("Save (*.txt)");
		saveMenuItem.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				saveMenuItemActionPerformed(evt);
			}
		});
		jMenu1.add(saveMenuItem);

		jMenuBar1.add(jMenu1);

		setJMenuBar(jMenuBar1);

		javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
		getContentPane().setLayout(layout);
		layout.setHorizontalGroup(
				layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
						.addGroup(layout.createSequentialGroup()
								.addContainerGap()
								.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
										.addComponent(jScrollPane1)
										.addGroup(layout.createSequentialGroup()
												.addComponent(prosesButton, javax.swing.GroupLayout.PREFERRED_SIZE, 110,
														javax.swing.GroupLayout.PREFERRED_SIZE)
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
												.addComponent(clearButton, javax.swing.GroupLayout.PREFERRED_SIZE, 119,
														javax.swing.GroupLayout.PREFERRED_SIZE)
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED,
														javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
												.addComponent(saveProsesButton, javax.swing.GroupLayout.PREFERRED_SIZE, 154,
														javax.swing.GroupLayout.PREFERRED_SIZE))
										.addGroup(layout.createSequentialGroup()
												.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
														.addComponent(jLabel1)
														.addComponent(jLabel2))
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
												.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
														.addComponent(jmlBarisTextField, javax.swing.GroupLayout.PREFERRED_SIZE, 111,
																javax.swing.GroupLayout.PREFERRED_SIZE)
														.addComponent(jmlKarakterTextField, javax.swing.GroupLayout.PREFERRED_SIZE, 111,
																javax.swing.GroupLayout.PREFERRED_SIZE))
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 41, Short.MAX_VALUE)
												.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
														.addComponent(jLabel4, javax.swing.GroupLayout.DEFAULT_SIZE,
																javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
														.addComponent(jLabel3, javax.swing.GroupLayout.DEFAULT_SIZE,
																javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
												.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
														.addComponent(jmlKonsonanTextField, javax.swing.GroupLayout.PREFERRED_SIZE, 111,
																javax.swing.GroupLayout.PREFERRED_SIZE)
														.addComponent(jmlVokalTextField, javax.swing.GroupLayout.PREFERRED_SIZE, 111,
																javax.swing.GroupLayout.PREFERRED_SIZE))))
								.addContainerGap()));
		layout.setVerticalGroup(
				layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
						.addGroup(layout.createSequentialGroup()
								.addContainerGap()
								.addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 221,
										javax.swing.GroupLayout.PREFERRED_SIZE)
								.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
								.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
										.addComponent(prosesButton)
										.addComponent(clearButton)
										.addComponent(saveProsesButton))
								.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
								.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
										.addGroup(layout.createSequentialGroup()
												.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
														.addComponent(jLabel1)
														.addComponent(jmlKarakterTextField, javax.swing.GroupLayout.PREFERRED_SIZE,
																javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
												.addGap(18, 18, 18)
												.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
														.addComponent(jLabel2)
														.addComponent(jmlBarisTextField, javax.swing.GroupLayout.PREFERRED_SIZE,
																javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
										.addGroup(layout.createSequentialGroup()
												.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
														.addComponent(jLabel3)
														.addComponent(jmlVokalTextField, javax.swing.GroupLayout.PREFERRED_SIZE,
																javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
												.addGap(18, 18, 18)
												.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
														.addComponent(jLabel4)
														.addComponent(jmlKonsonanTextField, javax.swing.GroupLayout.PREFERRED_SIZE,
																javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
								.addContainerGap(31, Short.MAX_VALUE)));

		pack();
	}// </editor-fold>//GEN-END:initComponents

	private void saveMenuItemActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_saveMenuItemActionPerformed
		// TODO add your handling code here:
		JFileChooser jfc = new JFileChooser(new File("c:\\"));

		jfc.setSelectedFile(new File("Notes.txt"));
		jfc.setFileFilter(new FileNameExtensionFilter("Text File (*.txt)", "txt"));
		jfc.showSaveDialog(null);
		File file = jfc.getSelectedFile();
		String content = contentTextArea.getText();

		try {
			FileOutputStream fos = new FileOutputStream(file.getCanonicalPath());
			fos.write(content.getBytes());
			fos.close();

			JOptionPane.showMessageDialog(this, "File berhasil disimpan");
		} catch (IOException ex) {
			Logger.getLogger(Notes.class.getName()).log(Level.SEVERE, null, ex);
		}
	}// GEN-LAST:event_saveMenuItemActionPerformed

	private void openMenuItemActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_openMenuItemActionPerformed
		// TODO add your handling code here:
		JFileChooser jfc = new JFileChooser(new File("c:\\"));
		jfc.setFileFilter(new FileNameExtensionFilter("Text File (*.txt)", "txt"));
		if (jfc.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
			FileInputStream fis = null;
			try {
				fis = new FileInputStream(jfc.getSelectedFile());
				String content = "";
				while (fis.available() > 0) {
					content += (char) fis.read();
				}
				contentTextArea.setText(content);
				fis.close();

				JOptionPane.showMessageDialog(this, "File berhasil dimuat");
			} catch (FileNotFoundException ex) {
				JOptionPane.showMessageDialog(this, "File tidak ditemukan");
			} catch (IOException ex) {
				JOptionPane.showMessageDialog(this, "File gagal dibaca");
			}
		}
	}// GEN-LAST:event_openMenuItemActionPerformed

	private void clearButtonActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_clearButtonActionPerformed
		// TODO add your handling code here:
		contentTextArea.setText("");
		jmlBarisTextField.setText("");
		jmlKarakterTextField.setText("");
		jmlVokalTextField.setText("");
		jmlKonsonanTextField.setText("");
	}// GEN-LAST:event_clearButtonActionPerformed

	private void prosesButtonActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_prosesButtonActionPerformed
		// TODO add your handling code here:
		String content = (contentTextArea.getText().replaceAll("\\s", "")).toLowerCase();
		int jmlBaris = content.equals("") ? 0 : contentTextArea.getLineCount();
		jmlBarisTextField.setText(String.valueOf(jmlBaris));
		int jmlKarakter = (int) content.chars().count();
		jmlKarakterTextField.setText(String.valueOf(jmlKarakter));
		int jmlVokal = (int) content.chars().filter(ch -> (ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o'))
				.count();
		jmlVokalTextField.setText(String.valueOf(jmlVokal));
		int jmlKonsonan = jmlKarakter - jmlVokal;
		jmlKonsonanTextField.setText(String.valueOf(jmlKonsonan));
	}// GEN-LAST:event_prosesButtonActionPerformed

	private void saveProsesButtonActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_saveProsesButtonActionPerformed
		// TODO add your handling code here:
		if (contentTextArea.getText().equals("")) {
			JOptionPane.showMessageDialog(this, "Text Area kosong..");
			return;
		}
		if (jmlKarakterTextField.getText().equals("") || jmlBarisTextField.getText().equals("")
				|| jmlVokalTextField.getText().equals("") || jmlKonsonanTextField.getText().equals("")) {
			JOptionPane.showMessageDialog(this, "Silahkan klik proses terlebih dahulu..");
			return;
		}

		JFileChooser jfc = new JFileChooser(new File("c:\\"));

		jfc.setSelectedFile(new File("Save Proses Note.txt"));
		jfc.setFileFilter(new FileNameExtensionFilter("Text File (*.txt)", "txt"));
		jfc.showSaveDialog(null);
		File file = jfc.getSelectedFile();
		String content = "Hasil Proses Text\n"
				+ "=================\nJumlah Karakter (diluar spasi) : " + jmlKarakterTextField.getText() + "\n"
				+ "Jumlah Baris : " + jmlBarisTextField.getText() + "\n"
				+ "Jumlah Huruf Vokal : " + jmlVokalTextField.getText() + "\n"
				+ "Jumlah Huruf Konsonan : " + jmlKonsonanTextField.getText();

		try {
			FileOutputStream fos = new FileOutputStream(file.getCanonicalPath());
			fos.write(content.getBytes());
			fos.close();

			JOptionPane.showMessageDialog(this, "File berhasil disimpan");
		} catch (IOException ex) {
			Logger.getLogger(Notes.class.getName()).log(Level.SEVERE, null, ex);
		}
	}// GEN-LAST:event_saveProsesButtonActionPerformed

	/**
	 * @param args the command line arguments
	 */
	public static void main(String args[]) {
		/* Set the Nimbus look and feel */
		// <editor-fold defaultstate="collapsed" desc=" Look and feel setting code
		// (optional) ">
		/*
		 * If Nimbus (introduced in Java SE 6) is not available, stay with the default
		 * look and feel.
		 * For details see
		 * http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html
		 */
		try {
			for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
				if ("Nimbus".equals(info.getName())) {
					javax.swing.UIManager.setLookAndFeel(info.getClassName());
					break;
				}
			}
		} catch (ClassNotFoundException ex) {
			java.util.logging.Logger.getLogger(Notes.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
		} catch (InstantiationException ex) {
			java.util.logging.Logger.getLogger(Notes.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
		} catch (IllegalAccessException ex) {
			java.util.logging.Logger.getLogger(Notes.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
		} catch (javax.swing.UnsupportedLookAndFeelException ex) {
			java.util.logging.Logger.getLogger(Notes.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
		}
		// </editor-fold>

		/* Create and display the form */
		java.awt.EventQueue.invokeLater(new Runnable() {
			public void run() {
				new Notes().setVisible(true);
			}
		});
	}

	// Variables declaration - do not modify//GEN-BEGIN:variables
	private javax.swing.JButton clearButton;
	private javax.swing.JTextArea contentTextArea;
	private javax.swing.JLabel jLabel1;
	private javax.swing.JLabel jLabel2;
	private javax.swing.JLabel jLabel3;
	private javax.swing.JLabel jLabel4;
	private javax.swing.JMenu jMenu1;
	private javax.swing.JMenuBar jMenuBar1;
	private javax.swing.JScrollPane jScrollPane1;
	private javax.swing.JTextField jmlBarisTextField;
	private javax.swing.JTextField jmlKarakterTextField;
	private javax.swing.JTextField jmlKonsonanTextField;
	private javax.swing.JTextField jmlVokalTextField;
	private javax.swing.JMenuItem openMenuItem;
	private javax.swing.JButton prosesButton;
	private javax.swing.JMenuItem saveMenuItem;
	private javax.swing.JButton saveProsesButton;
	// End of variables declaration//GEN-END:variables
}