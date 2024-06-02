<?php

namespace App\Controllers;

use App\Controllers\BaseController;
use App\Entities\Portfolio;
use App\Models\PortfolioModel;

class PortfolioController extends BaseController
{
    public $helpers = ['form'];

    public function index()
    {
        $model = new PortfolioModel();
        $portfolios = $model->findAll();

        $data = [
            'portfolios' => $portfolios
        ];

        return view('portfolio/index', $data);
    }

    public function create()
    {
        $rules = [
            'title' => 'required',
            'description' => 'required',
            'image' => 'uploaded[image]|ext_in[image,jpg,jpeg,png]'
        ];
        if ($this->request->getMethod() == 'POST' && $this->validate($rules)) {
            $imageFile = $this->request->getFile('image');
            $imageFileName = $imageFile->getRandomName();
            $imageFile->move(ROOTPATH . 'public/images/', $imageFileName);

            $portfolio = new Portfolio();
            $portfolio->title = $this->request->getPost('title');
            $portfolio->description = $this->request->getPost('description');
            $portfolio->image = "images/" . $imageFileName;

            $portfolioModel = new PortfolioModel();
            $portfolioModel->save($portfolio);

            return redirect()->to('/portfolio')->with('success_message', 'Successfully created a new portfolio.');
        } elseif ($this->request->getMethod() === 'POST') {
            return redirect()->to('/portfolio/create')->withInput()->with('errors', $this->validator->getErrors());
        }

        return view('portfolio/create');
    }

    public function update($id)
    {
        $model = new PortfolioModel();
        if (!$portfolio = $model->find($id)) {
            throw \CodeIgniter\Exceptions\PageNotFoundException::forPageNotFound();
        }

        $rules = [
            'title' => 'required',
            'description' => 'required',
            'image' => 'uploaded[image]|ext_in[image,jpg,jpeg,png]'
        ];
        if ($this->request->getMethod() == 'POST' && $this->validate($rules)) {
            $imageFile = $this->request->getFile('image');
            $imageFileName = $imageFile->getRandomName();

            if ($imageFile->isValid()) {
                unlink(ROOTPATH . 'public/' . $portfolio->image);
                $imageFile->move(ROOTPATH . 'public/images/', $imageFileName);
                $portfolio->image = "images/" . $imageFileName;
            }

            $portfolio->title = $this->request->getPost('title');
            $portfolio->description = $this->request->getPost('description');

            if ($portfolio->hasChanged()) {
                $model->save($portfolio);
            }

            return redirect()->to('/portfolio')->with('success_message', 'Successfully updated portfolio.');
        } elseif ($this->request->getMethod() == "POST") {
            return redirect()->to('/portfolio/update/' . $portfolio->id)->withInput()->with('errors', $this->validator->getErrors());
        }

        $data = [
            'portfolio' => $portfolio
        ];
        return view('portfolio/update', $data);
    }

    public function destroy($id)
    {
        $model = new PortfolioModel();
        if ($this->request->getMethod() == 'DELETE') {
            if (!$portfolio = $model->find($id)) {
                throw
                \CodeIgniter\Exceptions\PageNotFoundException::forPageNotFound();
            }
            $model->delete($portfolio->id);
        }

        return redirect()->to('/portfolio');
    }
}
