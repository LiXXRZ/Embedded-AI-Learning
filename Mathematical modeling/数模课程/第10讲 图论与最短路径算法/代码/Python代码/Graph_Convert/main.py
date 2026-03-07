import xlrd
import xlwt


if __name__ == '__main__':


    file = '../Graph_Convert/table.xls'
    # 打开文件
    wb = xlrd.open_workbook(filename=file)
    # 通过索引获取表格sheet页
    sheet1 = wb.sheet_by_index(0)
    cols = sheet1.ncols
    map = {}
    rmap = {}
    for i in range(0,cols):
        map[sheet1.cell_value(0,i)] = i + 1
        rmap[i + 1] = sheet1.cell_value(0,i)

    # 创建工作簿
    matrix = xlwt.Workbook()
    # 创建新的工作表sheet2
    sheet1 = matrix.add_sheet("Sheet1")

    for i in range(0, cols):
        for j in range(0, cols):
            if i == j or i > j :
                continue;
            print('请输入', rmap[i + 1], '到', rmap[j + 1], '的距离')
            dis = input()
            sheet1.write(i,j,dis)
            sheet1.write(j,i,dis)


