/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package praweek9.Controller;

import praweek9.Model.Database;
import praweek9.Model.Student;
import praweek9.View.StudentForm;

/**
 *
 * @author Muhammad Rayhan Faridh
 */
public class StudentController {
    private String fullname;
    private Student student;
    private StudentForm form;

    public StudentController(StudentForm form) {
        this.form = form;
    }

    public String formValidate() {
        student = new Student();

        String nimForm = form.getTextNim().getText();
        String firstNameForm = form.getTextFirstName().getText();
        String lastNameForm = form.getTextLastName().getText();
        String ageForm = form.getTextAge().getText();
        String asalForm = form.getComboAsal().getSelectedItem().toString();

        try {
            if (!nimForm.isBlank()) {
                if (nimForm.length() == 6) {
                    student.setNim(nimForm);
                } else {
                    return "Terjadi kesalahan input!\nPanjang NIM harus 6 digit.";
                }
            } else {
                return "NIM tidak boleh kosong!";
            }

            if (!firstNameForm.isBlank() && !lastNameForm.isBlank()) {
                if (firstNameForm.length() + lastNameForm.length() <= 50) {
                    fullname = firstNameForm + " " + lastNameForm;
                    if (fullname.matches("[a-zA-Z ]+")) {
                        student.setName(fullname);
                    } else {
                        return "Terjadi kesalahan input!\nTidak dapat menerima karakter selain alphabet.";
                    }
                } else {
                    return "Terjadi kesalahan input!\nPanjang nama maksimal 50 karakter.";
                }
            } else {
                return "Nama depan / nama belakang tidak boleh kosong!\nMasukkan nilai yang sama apabila nama hanya terdiri atas satu kata.";
            }

            if (!ageForm.isBlank()) {
                if (ageForm.matches("\\d+")) {
                    student.setAge(Integer.parseInt(ageForm));
                } else {
                    return "Usia harus berupa angka!";
                }
            } else {
                return "Usia tidak boleh kosong!";
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        Database.getInstance().addStudent(student);
        String result = "Daftar NIM dan Nama Mahasiswa yang telah disimpan: ";
        for (Student s : Database.getInstance().getAllStudents()) {
            result += "\n" + s.getNim() + " - " + s.getName();
        }

        this.ResetForm();
        return result;
    }

    public void ResetForm() {
        form.getTextNim().setText("");
        form.getTextFirstName().setText("");
        form.getTextLastName().setText("");
        form.getTextAge().setText("");
        form.getComboAsal().setSelectedIndex(0);
    }
}
