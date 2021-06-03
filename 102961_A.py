while True:
    try:
        s = input()
        if not s:
            break
        print('NO')
    except EOFError:
        break