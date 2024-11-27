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

/*-----------------------------customer-----------------------------*/
DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer`(
    `customer_id` varchar(10) NOT NULL,
    `name` varchar(20) NOT NULL,
    `contact_info` varchar(10) NOT NULL,
    `sex` varchar(1) NOT NULL,
    PRIMARY KEY (`customer_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES
    ('15-3215', 'Kim',  '012-12-345', 'F'),
    ('14-8964', 'Park', '012-69-874', 'M'),
    ('16-2166', 'Kim',  '012-61-236', 'F'),
    ('17-8457', 'Shin', '012-54-897', 'M'),
    ('13-2653', 'Lee',  '012-56-213', 'F'),
    ('14-2124', 'Choi', '012-21-234', 'M'),
    ('15-8955', 'Son',  '012-59-875', 'F'),
    ('11-2641', 'Kim',  '012-46-231', 'M'),
    ('17-9547', 'Kim',  '012-45-987', 'F'),
    ('11-4651', 'Lee',  '012-56-421', 'M');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

/*-----------------------------category-----------------------------*/
DROP TABLE IF EXISTS `category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `category` (
    `category_name` varchar(20) NOT NULL,
    `category_code` varchar(4) NOT NULL,
    PRIMARY KEY(`category_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
LOCK TABLES `category` WRITE;
/*!40000 ALTER TABLE `category` DISABLE KEYS */;
INSERT INTO `category` VALUES
    ('dairy',         'DAIR'),      /*유제품*/
    ('bakery',        'BAKE'),      /*빵*/
    ('snack',         'SNAC'),      /*간식류*/
    ('beverages',     'BEVE'),      /*음료*/
    ('tobacco',       'TOBA'),      /*담배*/
    ('grocery',       'GROC'),      /*식료품*/
    ('confectionery', 'CONF'),      /*과자*/
    ('prepared',      'PREP'),      /*포장식품*/
    ('meats',         'MEAT');      /*육류*/
/*!40000 ALTER TABLE `category` ENABLE KEYS */;
UNLOCK TABLES;

/*-----------------------------product-----------------------------*/
DROP TABLE IF EXISTS `product`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `product`(
    `product_id` varchar(10) NOT NULL,
    `category_name` varchar(10) DEFAULT NULL,
    `name` varchar(10) NOT NULL,
    `price` DECIMAL(10) NOT NULL,
    PRIMARY KEY (`product_id`),
    KEY `category_name` (`category_name`),
    CONSTRAINT `product_fk_1` FOREIGN KEY (`category_name`)
    REFERENCES `category` (`category_name`) ON DELETE SET NULL 
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
LOCK TABLES `product` WRITE;
/*!40000 ALTER TABLE `product` DISABLE KEYS */;
INSERT INTO `product` VALUES
    ('DAIR-001', 'dairy',         'Milk', 5500),
    ('DAIR-002', 'dairy',         'Buttuer', 5000),
    ('BAKE-001', 'bakery',        'Donut', 2300),
    ('BAKE-002', 'bakery',        'Cake', 5500),
    ('SNAC-001', 'snack',         'Dtos', 2000),
    ('SNAC-002', 'snack',         'Pchip', 3000),
    ('BEVE-001', 'beverages',     'Energy', 2300),
    ('BEVE-002', 'beverages',     'Latte', 3000),
    ('TOBA-001', 'tobacco',       'Mal Red', 4500),
    ('TOBA-002', 'tobacco',       'Mal Gold', 4500),
    ('GROC-001', 'grocery',       'Apple', 12000),
    ('GROC-002', 'grocery',       'Cucumber', 5500),
    ('CONF-001', 'confectionery', 'Snicker', 2000),
    ('CONF-002', 'confectionery', 'Swix', 1200),
    ('PREP-001', 'prepared',      'Chicken', 5500),
    ('PREP-002', 'prepared',      'Pasta', 4200),
    ('MEAT-001', 'meats',         'Beef', 4500),
    ('MEAT-002', 'meats',         'Pork', 3000);
/*!40000 ALTER TABLE `product` ENABLE KEYS */;
UNLOCK TABLES;

/*-----------------------------inventory-----------------------------*/
DROP TABLE IF EXISTS `inventory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `inventory`(
    `product_id` varchar(10) NOT NULL,
    `expire_date` varchar(10) NOT NULL,
    `stock_quantity` decimal(10) NOT NULL,
    PRIMARY KEY (`product_id`, `expire_date`),
    KEY `product_id` (`product_id`),
    CONSTRAINT `inventory_fk_1` FOREIGN KEY (`product_id`)
    REFERENCES `product`(`product_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
LOCK TABLES `inventory` WRITE;
/*!40000 ALTER TABLE `inventory` DISABLE KEYS */;
INSERT INTO `inventory` VALUES
    /*예제 데이터 : 케이크 유통기한별 재고*/
    ('BAKE-002', '2024-12-01', 21),
    ('BAKE-002', '2025-01-01', 50),
    ('BAKE-002', '2025-02-01', 50);
/*!40000 ALTER TABLE `inventory` ENABLE KEYS */;
UNLOCK TABLES;

/*-----------------------------reservation-----------------------------*/
DROP TABLE IF EXISTS `reservation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `reservation`(
    `reservation_id` varchar(10) NOT NULL,
    `customer_id` varchar(10) NOT NULL,
    `product_id` varchar(10) NOT NULL,
    `reservation_date` varchar(10) NOT NULL,
    `pickup_date` varchar(10) NOT NULL,
    `status_varchar` varchar(10) NOT NULL,
    PRIMARY KEY (`reservation_id`),
    KEY `product_id` (`product_id`),
    KEY `customer_id` (`customer_id`),
    CONSTRAINT `reservation_fk1` FOREIGN KEY (`customer_id`)
    REFERENCES `customer`(`customer_id`) ON DELETE CASCADE,
    CONSTRAINT `reservation_fk2` FOREIGN KEY (`product_id`)
    REFERENCES `product`(`product_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
LOCK TABLES `reservation` WRITE;
/*!40000 ALTER TABLE `reservation` DISABLE KEYS */;
INSERT INTO `reservation` VALUES
    ('241127-001', '15-3215', 'DAIR-001', '2024-11-27', '2024-12-01', 'valid');
/*!40000 ALTER TABLE `reservation` ENABLE KEYS */;
UNLOCK TABLES;



/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
