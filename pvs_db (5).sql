-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 20, 2024 at 09:47 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `pvs_db`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `adminid` int(15) NOT NULL,
  `username` varchar(50) NOT NULL,
  `email` varchar(50) NOT NULL,
  `admin_password` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`adminid`, `username`, `email`, `admin_password`) VALUES
(1, 'iz', 'iz@gmail.com', 'iz1234');

-- --------------------------------------------------------

--
-- Table structure for table `booking`
--

CREATE TABLE `booking` (
  `bookingID` int(50) NOT NULL,
  `vaccine_date` date NOT NULL,
  `pet_id` int(50) NOT NULL,
  `vaccine_id` int(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `payment`
--

CREATE TABLE `payment` (
  `payment_id` int(100) NOT NULL,
  `payment_amount` float(4,2) NOT NULL,
  `vaccine_id` int(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `payment`
--

INSERT INTO `payment` (`payment_id`, `payment_amount`, `vaccine_id`) VALUES
(1, 0.00, 23),
(2, 99.99, 22);

-- --------------------------------------------------------

--
-- Table structure for table `pet`
--

CREATE TABLE `pet` (
  `pet_id` int(15) NOT NULL,
  `pet_name` varchar(50) NOT NULL,
  `pet_age` varchar(50) NOT NULL,
  `pet_breed` varchar(50) NOT NULL,
  `pet_gender` char(1) NOT NULL,
  `user_id` int(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pet`
--

INSERT INTO `pet` (`pet_id`, `pet_name`, `pet_age`, `pet_breed`, `pet_gender`, `user_id`) VALUES
(4, 'oreo', '1 year', 'd', 'f', 6),
(5, 'ali', '2 years old', 'h', 'm', 6),
(6, 'comel', '3 years old', 'f', 'j', 4),
(7, 'nab', '2', 'hyper', 'm', 6),
(8, 'comot', '2 years old', 'maincoon', 'm', 7),
(9, 'oreo', '2 years old', 'mainecoon', 'f', 6),
(10, 'comot', '2 years old', 'mainecoon', 'm', 6),
(11, 'bulat', '2', 'mainecoon', 'm', 4),
(12, '1', '1', '1', '1', 3),
(14, 'snow', '2', 'maine', 'f', 4),
(15, 'yy', '2', 'yy', 'f', 4),
(16, 'manja', '2 ', 'mainecoon', 'm', 16);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `user_id` int(15) NOT NULL,
  `user_name` varchar(50) NOT NULL,
  `user_email` varchar(100) NOT NULL,
  `user_phone` varchar(15) NOT NULL,
  `user_password` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`user_id`, `user_name`, `user_email`, `user_phone`, `user_password`) VALUES
(1, 'anis', 'anis@gmail.com', '0182882273', 'anis123'),
(2, 'ali', 'ali@gmail.com', '019299821', 'ali123'),
(3, 'abu', 'abu@gmil.com', '014577896', 'abu124'),
(4, 'yaya', 'yaya@gmail.com', '13', 'yaya123'),
(5, 'afiq', 'afiq@gmail.com', '012982873', 'afiq123'),
(6, 'rab', 'rab@gmail.com', '019293828', 'rab1234'),
(7, 'yana', 'yana@gmail.com', '019275355', 'yana123'),
(8, 'liyana', 'liyana@gmail.com', '089765563', 'yana1234'),
(9, 'aznitah', 'aznitah@gmail.con', '01928238', 'aznitah123'),
(10, 'afrina', 'afrina@gmail.com', '01929291', 'afrina123'),
(11, '', '', '', ''),
(12, 'kkkk', 'kkkk@gmail.com', '01989812', 'kkk123'),
(13, 'jj', 'aa', '99288313', 'jj1234'),
(14, 'afuq', 'afuq12@gmail.com', '01992773873', 'afuq123'),
(15, 'alya', 'alya@gmail.com', '019283732', 'alya123'),
(16, 'acap', 'acap@gmail.com', '1234', 'acap123');

-- --------------------------------------------------------

--
-- Table structure for table `vaccination`
--

CREATE TABLE `vaccination` (
  `vaccine_id` int(50) NOT NULL,
  `vaccine_date` date NOT NULL,
  `vaccine_name` varchar(50) NOT NULL,
  `pet_id` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `vaccination`
--

INSERT INTO `vaccination` (`vaccine_id`, `vaccine_date`, `vaccine_name`, `pet_id`) VALUES
(22, '2024-03-03', 'p', '15'),
(23, '2024-04-04', 'p', '14'),
(24, '2024-02-02', 'N', '16');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`adminid`);

--
-- Indexes for table `booking`
--
ALTER TABLE `booking`
  ADD PRIMARY KEY (`bookingID`),
  ADD KEY `bookss` (`vaccine_id`),
  ADD KEY `booking` (`pet_id`);

--
-- Indexes for table `payment`
--
ALTER TABLE `payment`
  ADD PRIMARY KEY (`payment_id`),
  ADD KEY `pay` (`vaccine_id`);

--
-- Indexes for table `pet`
--
ALTER TABLE `pet`
  ADD PRIMARY KEY (`pet_id`),
  ADD KEY `users` (`user_id`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`user_id`);

--
-- Indexes for table `vaccination`
--
ALTER TABLE `vaccination`
  ADD PRIMARY KEY (`vaccine_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `adminid` int(15) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `booking`
--
ALTER TABLE `booking`
  MODIFY `bookingID` int(50) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `payment`
--
ALTER TABLE `payment`
  MODIFY `payment_id` int(100) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `pet`
--
ALTER TABLE `pet`
  MODIFY `pet_id` int(15) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `user_id` int(15) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT for table `vaccination`
--
ALTER TABLE `vaccination`
  MODIFY `vaccine_id` int(50) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `booking`
--
ALTER TABLE `booking`
  ADD CONSTRAINT `booking` FOREIGN KEY (`pet_id`) REFERENCES `pet` (`pet_id`),
  ADD CONSTRAINT `bookss` FOREIGN KEY (`vaccine_id`) REFERENCES `vaccination` (`vaccine_id`);

--
-- Constraints for table `pet`
--
ALTER TABLE `pet`
  ADD CONSTRAINT `users` FOREIGN KEY (`user_id`) REFERENCES `user` (`user_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
