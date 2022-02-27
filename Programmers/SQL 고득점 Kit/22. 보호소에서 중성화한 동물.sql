
SELECT ANIMAL_OUTS.ANIMAL_ID, ANIMAL_OUTS.ANIMAL_TYPE, ANIMAL_OUTS.NAME
from animal_outs
inner join animal_ins
on animal_outs.animal_id = animal_ins.animal_id
where animal_outs.sex_upon_outcome != animal_ins.sex_upon_intake
order by animal_outs.animal_id

-- inner join : 조인 한 후 한 쪽이 null인 row는 알아서 제거해줌.
-- 이 문제에서 ins에는 있고 out에는 없는 데이터는 필요 없음, 따라서 inner join 사용함 (그냥 join 해도 상관 없음)
-- where 조건문에 ins, outs에서 각각 성별 달라진 애 찾아 걔네만 표시