import type { IProductCharacter } from './IProductCharacter'

export interface IProductSchema {
    id: number
    name: string
    data: IProductCharacter
    description: string
    filenamePath: string
    webviewPath?: string
}
