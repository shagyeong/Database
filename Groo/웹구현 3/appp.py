from flask import Flask, render_template, request, redirect, url_for
import pymysql

app = Flask(__name__)

# 데이터베이스 연결 설정
db_config = {
    'host': 'localhost',  # 데이터베이스 호스트
    'user': 'root',       # MySQL 사용자 이름
    'password': 'thvcd!0103',  # MySQL 비밀번호
    'database': 'Coldcache',  # 데이터베이스 이름
}

@app.route('/')
@app.route('/main')
def display_main():
    return render_template('main.html')

@app.route('/product', methods=['GET'])
def display_products():
    # MySQL 데이터베이스 연결
    conn = pymysql.connect(**db_config)
    cursor = conn.cursor()
    # id ->product_id
    # category_name
    # name
    # price
    # 검색어 가져오기
    search_query = request.args.get('search', '')
    
    if search_query:
        # 검색어가 있는 경우 검색 쿼리 실행
        cursor.execute("SELECT * FROM product WHERE name LIKE %s", ('%' + search_query + '%',))
    else:
        # 검색어가 없는 경우 전체 데이터 가져오기
        cursor.execute("SELECT * FROM product")
    
    products = cursor.fetchall()
    conn.close()

    # 데이터를 HTML 템플릿으로 전달
    return render_template('product.html', products=products, search_query=search_query)

@app.route('/mypage')
def display_mypage():
    # MySQL 데이터베이스 연결
    conn = pymysql.connect(**db_config)
    cursor = conn.cursor()
# 마이페이지에 결제내역(payment) 추가
# 마이페이지에 customer table 추가
    # student 테이블 데이터 가져오기
    cursor.execute("SELECT * FROM customer where customer_id = '15-3215'")
    customers = cursor.fetchall()

    cursor.execute("SELECT * FROM payment where customer_id = '15-3215'")
    payments = cursor.fetchall()
    conn.close()

    # 데이터를 HTML 템플릿으로 전달
    return render_template('mypage.html', customers=customers, payments=payments)

@app.route('/promotion_product', methods=['GET', 'POST'])
def display_promotion_product():
    # MySQL 데이터베이스 연결
    conn = pymysql.connect(**db_config)
    cursor = conn.cursor()
    # id -> product_id
    # decription -> event_description
    # duration 추가
    if request.method == 'POST':
        product_id = request.form.get('id')
        try:
            cursor.execute("SELECT * FROM event_product WHERE product_id = %s", (product_id,))
            event_product = cursor.fetchone()

            ################## 기본 키 중복 문제로 삽입 문제 발생
            if event_product:
                cursor.execute("INSERT INTO cart (cart_id, customer_id, product_id, name, price) VALUES (%s, %s, %s, %s, %s)", ('241127-001', '15-3215', event_product[0], event_product[1], event_product[2]))
                conn.commit()
                print("장바구니에 상품이 추가되었습니다.")
            else:
                print("상품을 찾을 수 없습니다.")
                
        except Exception as e:
            print(f"오류 발생: {e}")
            conn.rollback()

    # 검색어 가져오기
    search_query = request.args.get('search', '')
    
    if search_query:
        # 검색어가 있는 경우 검색 쿼리 실행
        cursor.execute("SELECT * FROM event_product WHERE name LIKE %s", ('%' + search_query + '%',))
    else:
        # 검색어가 없는 경우 전체 데이터 가져오기
        cursor.execute("SELECT * FROM event_product")

    event_products = cursor.fetchall()
    conn.close()

    # 데이터를 HTML 템플릿으로 전달
    return render_template('promotion_product.html', event_products=event_products, search_query=search_query)

@app.route('/save_promotion')
def display_save_promotion():
    # MySQL 데이터베이스 연결
    conn = pymysql.connect(**db_config)
    cursor = conn.cursor()

    # customer_id 추가
    # product_id
    # quantity
    
    # student 테이블 데이터 가져오기
    cursor.execute("SELECT * FROM save_event_product")
    save_event_products = cursor.fetchall()

    conn.close()

    # 데이터를 HTML 템플릿으로 전달
    return render_template('save_promotion.html', save_event_products=save_event_products)

@app.route('/cart', methods=['GET', 'POST'])
def display_cart():
    # MySQL 데이터베이스 연결
    conn = pymysql.connect(**db_config)
    cursor = conn.cursor()

    # reserves_id(예약 ID)
    # customer_id(고객 ID)
    # product_id(상품 ID)
    # reserves_date(예약 날짜)
    # pickup_date(픽업 날짜)
    # status(예약 상태)

    if request.method == 'POST':
        action = request.form.get('action')
        product_id = request.form.get('id')
        if action == 'delete':
            try:
                cursor.execute("DELETE FROM cart WHERE product_id = %s", (product_id,))
                conn.commit()
                print("장바구니에서 삭제되었습니다.")
            except Exception as e:
                print(f"오류 발생: {e}")
                conn.rollback()
        elif action == 'save':
            try:
                cursor.execute("SELECT * FROM cart WHERE product_id = %s", (product_id,))
                product = cursor.fetchone()

                if product:
                    cursor.execute("INSERT INTO save_event_product (customer_id, product_id, name, quantity) VALUES (%s, %s, %s, %s)", (product[1], product[2], product[3], 99))
                    cursor.execute("INSERT INTO payment (customer_id, product_id, payment_date, product_name, quantity, total_payment) VALUES (%s, %s, %s, %s, %s, %s)", (product[1], product[2], '2024-11-29', product[3], 99, product[4]))
                    conn.commit()
                    print("구매 목록에 상품이 추가되었습니다.")
            except Exception as e:
                print(f"오류 발생: {e}")
                conn.rollback()

    # student 테이블 데이터 가져오기
    cursor.execute("SELECT cart.cart_id, cart.customer_id, cart.product_id, cart.name, cart.price, event_product.event_description, event_product.duration FROM cart INNER JOIN event_product ON cart.product_id = event_product.product_id")
    cart_items = cursor.fetchall()

    conn.close()

    # 데이터를 HTML 템플릿으로 전달
    return render_template('cart.html', cart_items=cart_items)



if __name__ == "__main__":
    app.run(debug=True)
