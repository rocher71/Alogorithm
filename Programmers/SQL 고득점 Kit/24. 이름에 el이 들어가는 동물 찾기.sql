SELECT ANIMAL_ID, NAME
from animal_ins
where name REGEXP 'el' and animal_type = 'dog'
order by name

-- where 조건에 regexp 즉 정규표현식 사용.
-- 여러가지 문자열이 포함된 구문을 쓰고싶으면 regexp 'a|b|c' 이렇게 or 연산자로 이어서 쓰면 됨.