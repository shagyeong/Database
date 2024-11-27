from flask import Flask, render_template
import pymysql

app = Flask(__name__)

# 데이터베이스 연결 설정
db_config = {
    'host': 'localhost',  # 데이터베이스 호스트
    'user': 'shagyeong',       # MySQL 사용자 이름
    'password': '1234',  # MySQL 비밀번호
    'database': 'University',  # 데이터베이스 이름
}

@app.route('/product')
def display_students():
    # MySQL 데이터베이스 연결
    conn = pymysql.connect(**db_config)
    cursor = conn.cursor()

    # student 테이블 데이터 가져오기
    cursor.execute("SELECT * FROM student")
    students = cursor.fetchall()

    conn.close()

    # 데이터를 HTML 템플릿으로 전달
    return render_template('product.html', students=students)

@app.route('/mypage')
def display_mypage():
    # MySQL 데이터베이스 연결
    conn = pymysql.connect(**db_config)
    cursor = conn.cursor()

    # student 테이블 데이터 가져오기
    cursor.execute("SELECT * FROM student")
    students = cursor.fetchall()

    conn.close()

    # 데이터를 HTML 템플릿으로 전달
    return render_template('mypage.html', students=students)

@app.route('/promotion_product')
def display_promotion_product():
    # MySQL 데이터베이스 연결
    conn = pymysql.connect(**db_config)
    cursor = conn.cursor()

    # student 테이블 데이터 가져오기
    cursor.execute("SELECT * FROM student")
    students = cursor.fetchall()

    conn.close()

    # 데이터를 HTML 템플릿으로 전달
    return render_template('promotion_product.html', students=students)

@app.route('/save_promotion')
def display_save_promotion():
    # MySQL 데이터베이스 연결
    conn = pymysql.connect(**db_config)
    cursor = conn.cursor()

    # student 테이블 데이터 가져오기
    cursor.execute("SELECT * FROM student")
    students = cursor.fetchall()

    conn.close()

    # 데이터를 HTML 템플릿으로 전달
    return render_template('save_promotion.html', students=students)

@app.route('/cart')
def display_cart():
    # MySQL 데이터베이스 연결
    conn = pymysql.connect(**db_config)
    cursor = conn.cursor()

    # student 테이블 데이터 가져오기
    cursor.execute("SELECT * FROM student")
    students = cursor.fetchall()

    conn.close()

    # 데이터를 HTML 템플릿으로 전달
    return render_template('cart.html', students=students)


if __name__ == "__main__":
    app.run(debug=True)
