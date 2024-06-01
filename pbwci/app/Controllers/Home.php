<?php

namespace App\Controllers;

use \App\Models\UserModel;

class Home extends BaseController
{
    public function index(): string
    {
        return view('index');
    }

    public function signinAuth()
    {
        $session = session();
        $userModel = new UserModel();
        $username = $this->request->getVar('username');
        $password = $this->request->getVar('password');

        $data = $userModel->where('username', $username)->first();

        if ($data) {
            $pass = $data['password'];
            $verify_pass = password_verify($password, $pass);
            if ($verify_pass) {
                $ses_data = [
                    'username' => $data['username'],
                    'isSignedIn' => TRUE
                ];
                $session->set($ses_data);
                return redirect()->to('/Home/meeting');
            } else {
                $session->setFlashdata('msg', 'Password is incorrect');
                return redirect()->to('/Home');
            }
        } else {
            $session->setFlashdata('msg', 'Username does not exist');
            return redirect()->to('/Home');
        }
    }

    public function meeting()
    {
        $session = session();
        if ($session->get('isSignedIn')) {
            $data = [
                'username' => $session->get('username')
            ];

            return view('meeting', $data);
        } else {
            return redirect()->to('/Home');
        }
    }

    public function signout()
    {
        $session = session();
        $session->destroy();
        return redirect()->to('/Home');
    }
}
