SELECT animal_outs.animal_id ANIMAL_ID, animal_outs.name NAME
from animal_outs
left join animal_ins
on animal_outs.animal_id = animal_ins.animal_id
where animal_outs.datetime < animal_ins.datetime
order by animal_ins.datetime

-- where 조건문에 날짜 비교식 넣기. 날짜는 그냥 비교 연산자로 비교됨.