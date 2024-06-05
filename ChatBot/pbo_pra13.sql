-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Jun 05, 2024 at 12:49 AM
-- Server version: 8.0.30
-- PHP Version: 8.3.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `pbo_pra13`
--

-- --------------------------------------------------------

--
-- Table structure for table `answer`
--

CREATE TABLE `answer` (
  `id` int NOT NULL,
  `answer` varchar(255) NOT NULL,
  `category` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `answer`
--

INSERT INTO `answer` (`id`, `answer`, `category`) VALUES
(1, 'waalaikumussalam', 'salamIslam'),
(2, 'hai halooo', 'salam'),
(3, 'kabar aku baik, kamu gimana??', 'kabar'),
(4, 'aku adalah chatbot', 'aku'),
(5, 'kabarku buruk nihh :((', 'kabar'),
(6, 'halooo', 'salam'),
(7, 'hai haiiii', 'salam'),
(8, 'aku diputusin pacar hiks:(', 'kabarBuruk');

-- --------------------------------------------------------

--
-- Table structure for table `ask`
--

CREATE TABLE `ask` (
  `id` int NOT NULL,
  `ask` varchar(255) NOT NULL,
  `category` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `ask`
--

INSERT INTO `ask` (`id`, `ask`, `category`) VALUES
(1, 'hai', 'salam'),
(2, 'halo', 'salam'),
(3, 'assalamualaikum', 'salamIslam'),
(4, 'wassalamualaikum', 'salamIslam'),
(5, 'gimana kabarnya?', 'kabar'),
(6, 'apa kabar?', 'kabar'),
(7, 'kamu siapa?', 'aku'),
(8, 'loh kenapa?', 'kabarBuruk');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `answer`
--
ALTER TABLE `answer`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `ask`
--
ALTER TABLE `ask`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `answer`
--
ALTER TABLE `answer`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `ask`
--
ALTER TABLE `ask`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
