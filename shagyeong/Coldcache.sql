Create database if not exists Coldcache;
Use Coldcache;

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

-- CREATE TABLE `advisor` (
--   `s_ID` varchar(5) NOT NULL,
--   `i_ID` varchar(5) DEFAULT NULL,
--   PRIMARY KEY (`s_ID`),
--   KEY `i_ID` (`i_ID`),
--   CONSTRAINT `advisor_ibfk_1` FOREIGN KEY (`i_ID`) REFERENCES `instructor` (`ID`) ON DELETE SET NULL,
--   CONSTRAINT `advisor_ibfk_2` FOREIGN KEY (`s_ID`) REFERENCES `student` (`ID`) ON DELETE CASCADE
-- ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
-- /*!40101 SET character_set_client = @saved_cs_client */;

-- LOCK TABLES `advisor` WRITE;
-- /*!40000 ALTER TABLE `advisor` DISABLE KEYS */;
-- INSERT INTO `advisor` VALUES ('12345','10101'),('44553','22222'),('45678','22222'),('00128','45565'),('76543','45565'),('23121','76543'),('98988','76766'),('76653','98345'),('98765','98345');
-- /*!40000 ALTER TABLE `advisor` ENABLE KEYS */;
-- UNLOCK TABLES;



DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer` (
    `ID` varchar(10) NOT NULL,
    `name` varchar(20) NOT NULL,
    `contact_info` varchar(10) NOT NULL,
    `sex` varchar(1) NOT NULL,
    PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES
    ('15-3215', 'Kim', '010-12-345', 'F'),
    ('14-8964', 'Park', '010-69-874', 'M'),
    ('16-2166', 'Kim', '010-61-236', 'F'),
    ('17-8457', 'Shin', '010-54-897', 'M'),
    ('13-2653', 'Lee', '010-56-213', 'F'),
    ('14-2124', 'Choi', '010-21-234', 'M'),
    ('15-8955', 'Son', '010-59-875', 'F'),
    ('11-2641', 'Kim', '010-46-231', 'M'),
    ('17-9547', 'Kim', '010-45-987', 'F'),
    ('11-4651', 'Lee', '010-56-421', 'M');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
