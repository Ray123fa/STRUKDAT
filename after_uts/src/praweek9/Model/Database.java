/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package praweek9.Model;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Muhammad Rayhan Faridh
 */
public class Database {
	public static Database instance;
	private ArrayList<Student> data = new ArrayList<>();

	private Database() {
	}

	public static synchronized Database getInstance() {
		if (instance == null) {
			instance = new Database();
		}
		return instance;
	}

	public void addStudent(Student student) {
		data.add(student);
	}

	public List<Student> getAllStudents() {
		return data;
	}
}
