SELECT ANIMAL_TYPE, 
    case when name is null then 'No name' else name end as NAME,
SEX_UPON_INTAKE
from animal_ins
order by animal_id

-- case when 조건 then 맞으면 실행문 else 아니면 실행문 end as 칼럼 명