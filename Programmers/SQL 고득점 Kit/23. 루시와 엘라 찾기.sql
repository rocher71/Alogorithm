SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
from animal_ins
where name = 'Lucy' 
    or name = 'Ella'
    or name = 'Pickle'
    or name = 'Rogan'
    or name = 'Sabrina'
    or name = 'Mitty'
order by animal_id


-- 찾는 이름들을 or 조건으로 묶어서 비교 