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

/*-----------------------------cart-----------------------------*/
DROP TABLE IF EXISTS `cart`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cart`(
    `cart_id` varchar(10) NOT NULL,
    `customer_id` varchar(10) NOT NULL,
    `product_id` varchar(10) NOT NULL,
    `name` varchar(10) NOT NULL,
    `price` DECIMAL(10) NOT NULL,
    PRIMARY KEY (`cart_id`),
    KEY `customer_id` (`customer_id`),
    CONSTRAINT `cart_fk1` FOREIGN KEY (`customer_id`)
    REFERENCES `customer`(`customer_id`) ON DELETE CASCADE,
    CONSTRAINT `cart_fk2` FOREIGN KEY (`product_id`)
    REFERENCES `product`(`product_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
LOCK TABLES `cart` WRITE;
/*!40000 ALTER TABLE `cart` DISABLE KEYS */;
INSERT INTO `cart` VALUES
    ('241127-001', '15-3215', 'DAIR-001', 'Milk', 5500);
/*!40000 ALTER TABLE `cart` ENABLE KEYS */;
UNLOCK TABLES;

/*-----------------------------payment-----------------------------*/
DROP TABLE IF EXISTS `payment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `payment`(
    `customer_id` varchar(10) NOT NULL,
    `product_id` varchar(10) NOT NULL,
    `payment_date` varchar(10) NOT NULL,
    `product_name` varchar(10) NOT NULL,
    `quantity` decimal(10) NOT NULL,
    `total_payment` decimal(10) NOT NULL,
    PRIMARY KEY (`customer_id`, `product_id`, `payment_date`),
    KEY `customer_id` (`customer_id`),
    CONSTRAINT `payment_fk1` FOREIGN KEY (`customer_id`)
    REFERENCES `customer`(`customer_id`) ON DELETE CASCADE,
    CONSTRAINT `payment_fk2` FOREIGN KEY (`product_id`)
    REFERENCES `product`(`product_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
LOCK TABLES `payment` WRITE;
/*!40000 ALTER TABLE `payment` DISABLE KEYS */;
INSERT INTO `payment` VALUES
    ('15-3215', 'BEVE-001', '2024-11-01', 'Energy', 3, 4600);
/*!40000 ALTER TABLE `payment` ENABLE KEYS */;
UNLOCK TABLES;

/*-----------------------------event_product-----------------------------*/
DROP TABLE IF EXISTS `event_product`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `event_product`(
    `product_id` varchar(10) NOT NULL,
    `name` varchar(10) NOT NULL,
    `price` DECIMAL(10) NOT NULL,
    `event_description` varchar(20) NOT NULL,
    `duration` varchar(23) NOT NULL,
    PRIMARY KEY (`product_id`),
    KEY `product_id` (`product_id`),
    CONSTRAINT `event_product_fk1` FOREIGN KEY (`product_id`)
    REFERENCES `prodcut`(`product_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
LOCK TABLES `event_product` WRITE;
/*!40000 ALTER TABLE `event_product` DISABLE KEYS */;
INSERT INTO `event_product` VALUES
    ('BEVE-001', 'Energy', 2300 ,'2 + 1', '2024-11-01 ~ 2024-12-31'),
    ('SNAC-001', 'Dtos', 2000, '1 + 1', '2024-11-01 ~ 2024-11-30'),
    ('GROC-001', 'Apple', 12000, '1 + 1', '2024-11-19 ~ 2024-11-21'),
    ('GROC-002', 'Cucumber', 5500, '3 + 2', '2024-12-01 ~ 2024-12-05'),
    ('CONF-001', 'Snicker', 2000, '4 + 2', '2024-11-30 ~ 2024-12-03'),
    ('CONF-002', 'Swix', 1200, '2 + 2', '2024-11-20 ~ 2024-11-30'),
    ('PREP-001', 'Chicken', 5500, '1 + 3', '2024-11-15 ~ 2024-11-27'),
    ('PREP-002', 'Pasta', 4200, '2 + 3', '2024-12-01 ~ 2024-12-31'),
    ('MEAT-001', 'Beef', 4500, '1 + 1', '2024-11-29 ~ 재료 소진 까지'),
    ('MEAT-002', 'Pork', 3000, '1 + 1', '2024-11-29 ~ 재료 소진 까지');
/*!40000 ALTER TABLE `event_product` ENABLE KEYS */;
UNLOCK TABLES;

/*-----------------------------save_event_product-----------------------------*/
DROP TABLE IF EXISTS `save_event_product`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `save_event_product`(
    `customer_id` varchar(10) NOT NULL,
    `product_id` varchar(10) NOT NULL,
    `name` varchar(10) NOT NULL,
    `quantity` decimal(10) NOT NULL,
    `save_duration` int Default 3,
    PRIMARY KEY (`customer_id`, `product_id`),
    KEY `customer_id` (`customer_id`),
    CONSTRAINT `save_event_product_fk1` FOREIGN KEY (`customer_id`)
    REFERENCES `customer` (`customer_id`) ON DELETE CASCADE,
    CONSTRAINT `save_event_product_fk2` FOREIGN KEY (`product_id`)
    REFERENCES `product` (`product_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
LOCK TABLES `save_event_product` WRITE;
/*!40000 ALTER TABLE `save_event_product` DISABLE KEYS */;
INSERT INTO `save_event_product` VALUES
    ('15-3215', 'BEVE-001', 'Energy', 1, 3);
/*!40000 ALTER TABLE `save_event_product` ENABLE KEYS */;
UNLOCK TABLES;


/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;