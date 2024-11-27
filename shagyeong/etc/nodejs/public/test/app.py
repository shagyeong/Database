from flask import Flask, render_template
import pymysql

app = Flask(__name__)

# MySQL 데이터베이스 연결 정보
db_config = {
    'host': 'localhost',        # 데이터베이스 호스트
    'user': 'root',             # 사용자 이름
    'password': 'seyoon4501',     # 비밀번호
    'database': 'university'   # 데이터베이스 이름
}

def get_products():
    """데이터베이스에서 상품 데이터 가져오기"""
    connection = pymysql.connect(**db_config)
    cursor = connection.cursor(pymysql.cursors.DictCursor)  # 결과를 딕셔너리 형태로 반환
    cursor.execute("SELECT * FROM student")               # 상품 테이블 쿼리
    products = cursor.fetchall()
    connection.close()
    return products

@app.route('/')
def product_page():
    products = get_products()  # 데이터베이스에서 상품 데이터 가져오기
    return render_template('products.html', student=student)

if __name__ == '__main__':
    app.run(debug=True)



from flask import Flask, render_template

# Flask 애플리케이션 객체 생성
app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html')  # templates/index.html 파일 렌더링

if __name__ == '__main__':
    app.run(debug=True)  # Flask 서버 실행
