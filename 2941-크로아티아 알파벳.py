def main():
    croatian = ('c=','c-','dz=','d-','lj','nj','s=','z=')
    str = input()

    count = 0

    for i in croatian:
        count += str.count(i)
        str = str.replace(i,'_')

    str = str.replace('_','')
    count += len(str)

    print(count)

if __name__ == "__main__":
    main()
