-- 코드를 입력하세요
SELECT name, count (name) as cnt
from animal_ins
group by name
having cnt > 1
order by name

-- having은 group by 다음에!!
