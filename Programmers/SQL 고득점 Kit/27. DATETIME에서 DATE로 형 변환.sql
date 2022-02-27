-- 복습 필수 검색함

SELECT ANIMAL_ID, NAME, DATE_FORMAT(DATETIME, '%Y-%m-%d') AS '날짜'
FROM ANIMAL_INS
order by animal_id

-- 꼭 datediff로 type 바꿀 필요 없음.
-- Y-y, M-m, D-d 가 다 출력 결과가 다르니까 꼭 알고있기.