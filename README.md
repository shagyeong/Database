# Database: 2024-2 데이터베이스(나)반 팀 프로젝트
## 프로젝트 요약
### 웹
- HTML5
- CSS
- JavaScript
- Python Flask
### 데이터베이스
- MySQL
### 테스트
- 데이터베이스 연결 설정(app.py)
    ```python
    db_config = {
        'host': 'localhost',    # 데이터베이스 호스트
        'user': 'username',             # MySQL 사용자명 입력
        'password': '1234',         # MySQL 비밀번호 입력
        'database': 'Coldcache' # 데이터베이스 이름
    }
    ```
- 데이터베이스 임포트
    ```
    $ mysql -u username -p
    Enter password:
    mysql> souruce ./Clodcache.sql;
    mysql> show databases;
    +--------------------+
    | Database           |
    +--------------------+
    | Coldcache          |
    +--------------------+
    1 rows in set (0.00 sec)
    mysql> quit
    Bye
    $ 
    ```
- 웹 구동
    ```
    $ python3 app.py
     * Serving Flask app 'app'
     * Debug mode: on
    WARNING: This is a development server. Do not use it in a production deployment. Use a production WSGI server instead.
     * Running on http://127.0.0.1:5000
    Press CTRL+C to quit
    ```
