function makeFunc() {
  var name = 'Mozilla';
  function displayName() {
    console.log(name);
  }
  return displayName;
}

var myFunc = makeFunc();
//myFunc������ displayName�� ������
//��ȿ������ ������ ȯ���� ����
myFunc();
//���ϵ� displayName �Լ��� ����(name ������ ����)
